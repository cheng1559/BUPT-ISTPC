#!/bin/bash

# Author: CaveNightingale, License: CC0

# This script is used to build a zip file for LuoGu Judge
# Usage: ./buildzip.sh
# at the root of the problem directory
# It will generate a data.zip file in the current directory
# Notice that the inlined checker and validator will be with extension .cpp instead of .cc,
# while jury and generator will not appear in the zip file

# Judge type 
no_checker=0
no_validator=0
no_interactor=1
no_jury=0

test_count=0
time_limit=1
testlib_path=$PWD/../..

while getopts "cvij" opt; do
	case $opt in
		c)
			no_checker=1
			echo "Building without special judge..."
			;;
		v)
			no_validator=1
			echo "Building without validator..."
			;;
		i)
			no_interactor=0
			no_checker=1
			echo "Building with interactor..."
			;;
		j)
			no_jury=1
			echo "Building without jury..."
			;;
		\?)
			exit 1
			;;
	esac
done

# Create temp dir
work_tmp=$(mktemp -d)
echo "Working directory: $work_tmp"

abort() {
	echo -e "\e[1m\e[31mBuild failed\e[0m: $@" >&2
	echo -e "\e[1m\e[36mPress enter to continue...\e[0m" >&2
	read < /dev/tty
	rm -rf $work_tmp
	exit 1
}

assert() {
	local msg=$1
	shift
	if ! "$@"; then
		abort "$msg"
	fi
}

run_jury() {
	local file=$1
	shift
	if [[ -f "$here/$file" ]]; then
		echo "        Running jury $file on test $test_count..."
		if [[ -f "data/data$test_count.out" ]]; then
			cp "data/data$test_count.out" "data/data$test_count.ans"
		fi
		if [[ $no_jury -eq 0 ]]; then
			start_time=$(date +%s.%N)
			assert "Jury \`$file\` failed on test $test_count: Runtime error" "$@" < "data/data$test_count.in" > "data/data$test_count.out"
			end_time=$(date +%s.%N)
		fi
		if [[ $(echo "$end_time" - "$start_time" '>' "$time_limit" | bc) -eq 1 ]]; then
			abort "Jury \`$file\` failed on test $test_count: Time limit exceeded"
		fi
		if [[ ! -f "data/data$test_count.ans" ]]; then
			cp "data/data$test_count.out" "data/data$test_count.ans"
		fi
		if [[ $no_checker -eq 0 ]]; then
			checker_comment=$(./checker "data/data$test_count.in" "data/data$test_count.out" "data/data$test_count.ans" 2>&1)
			if [[ $? -ne 0 ]]; then
				abort "Jury \`$file\` failed on test $test_count: Wrong Answer. $checker_comment"
			fi
		else
			if ! diff -Z -B -w "data/data$test_count.out" "data/data$test_count.ans" 2>/dev/null >/dev/null; then 
				abort "Jury \`$file\` failed on test $test_count: Wrong Answer"
			fi
		fi
	fi
}

# Add test case
# Usage: test_case <subtask> <score> <command>
test_case() {
	echo "    Generating test $test_count..."
	local subtask=$1
	local score=$2
	shift
	shift
	local here=$(pwd)
	cd $work_tmp
	assert "Failed to generate test $test_count" "$@" > "data/data$test_count.in"
	if [[ $no_validator -eq 0 ]]; then
		assert "Test $test_count is invalid" ./validator < "data/data$test_count.in"
	fi
	if [[ $no_interactor -eq 1 ]]; then # Actually, we have no way to check interactor
		run_jury jury.cc ./jury # Assert that jury in all languages can pass. Especially for python3
		run_jury jury.c ./c.jury
		run_jury jury.java java -cp . jury
		run_jury jury.py python3 jury.py
	fi
	echo "data$test_count.in:" >> "data/config.yml"
	echo "  subtaskId: $subtask" >> "data/config.yml"
	echo "  score: $score" >> "data/config.yml"
	echo "  timeLimit: $(($time_limit * 2000))" >> "data/config.yml" # LuoGu's machine is slow, scale it by 2
	echo >> "data/config.yml" # LuoGu's memory measurement has big error, so we don't use it
	cd $here
	test_count=$(($test_count + 1))
}

# Assert that an incorrect solution will fail, notice that this function will not check the time limit
# Only python3 is supported
# Usage: reject <solution.py>
reject() {
	file=$1
	shift
	echo "    Asserting that $file is rejected..."
	local here=$(pwd)
	cd $work_tmp
	i=0
	while true; do
		if [[ ! -f "data/data$i.in" ]]; then
			break
		fi
		python3 $file < "data/data$i.in" > "tmp$i.out" 2>/dev/null
		if [[ $? -ne 0 ]]; then
			rm "tmp$i.out"
			echo "        Ok. $file failed on test $i: Runtime error"
			cd $here
			return 0
		fi
		if [[ $no_checker -eq 0 ]]; then
			if ! ./checker "data/data$i.in" "tmp$i.out" "data/data$i.out" 2>/dev/null >/dev/null; then
				rm "tmp$i.out"
				echo "        Ok. $file failed on test $i: Wrong Answer"
				cd $here
				return 0
			fi
		else
			if ! diff -Z -B -w "tmp$i.out" "data/data$i.out" 2>/dev/null >/dev/null; then
				rm "tmp$i.out"
				echo "        Ok. $file failed on test $i: Wrong Answer"
				cd $here
				return 0
			fi
		fi
		rm "tmp$i.out"
		((i++))
	done
	abort "$file passed all tests, but it should not"
}

# Online Judge don't allow us to include custom files, so inline them
declare -A stack
inline_file() {
	IFS=$'\n'
	for line in $(cat "$1"); do
		if echo "$line" | grep -q '^# *include *"'; then
			local file=$(echo "$line" | cut -d'"' -f2)
			if [[ -f "$file" ]]; then
				if [[ -z "${stack[$file]}" ]]; then
					stack[$file]=1
					inline_file "$file"
					unset stack[$file]
				else
					abort "Circular dependency detected: $file when inlining $1"
				fi
			else
				echo "$line" # Not found, just print it
			fi
		else
			echo "$line"
		fi
	done
}

# Check the files
echo "Checking files..."
if [[ $no_checker -eq 0 ]]; then
	if [[ ! -f checker.cc ]]; then
		echo -e "\e[1m\e[33mWarning\e[0m: Checker not found. Building without checker implicitly..."
		no_checker=1
	fi
fi
if [[ $no_validator -eq 0 ]]; then
	if [[ ! -f validator.cc ]]; then
		echo -e "\e[1m\e[33mWarning\e[0m: Validator not found. Building without validator implicitly..."
		no_validator=1
	fi
fi
if [[ ! -f jury.cc && ! -f jury.c && ! -f jury.java && ! -f jury.py ]]; then
	abort "Jury not found"
fi
if [[ ! -f config.sh ]]; then
	abort "Config not found"
fi

# Compile files
cp -r * $work_tmp
echo "Compiling files..."
ls *.cc | while read file; do
	echo "    Compiling $file..."
	assert "Compile failed: $file" g++ -std=c++20 "-I$testlib_path" -O2 -Wall -Wextra -Wfatal-errors -Wno-unused-result -o "$work_tmp/${file%.cc}" "$file"
done
if [[ -f jury.c ]]; then
	echo "    Compiling jury.c..."
	assert "Compile failed: jury.c" gcc -std=c11 "-I$testlib_path" -O2 -Wall -Wextra -Wfatal-errors -Wno-unused-result -o "$work_tmp/c.jury" "jury.c"
fi
if [[ -f jury.java ]]; then
	echo "    Compiling jury.java..."
	assert "Compile failed: jury.java" javac -cp "$testlib_path" -d "$work_tmp" "jury.java"
fi

# Build test cases from config.sh
mkdir -p $work_tmp/data
echo "Building test cases..."
source config.sh

# Pack files
echo "Packaging files..."
if [[ $no_checker -eq 0 ]]; then
	echo "    Inlining checker..."
	inline_file checker.cc > $work_tmp/data/checker.cpp
fi
if [[ $no_validator -eq 0 ]]; then
	echo "    Inlining validator..."
	inline_file validator.cc > $work_tmp/data/validator.cpp
fi
if [[ $no_interactor -eq 0 ]]; then
	echo "    Inlining interactor..."
	inline_file interactor.cc > $work_tmp/data/interactor.cpp
fi
rm -f data.zip
here=$(pwd)
cd $work_tmp/data
rm -f *.ans 2>/dev/null || true
echo "    Zipping..."
zip -9 -X -q $here/data.zip *
cd $here

# Clean up
rm -rf $work_tmp
echo -e "\e[1m\e[32mBuild success\e[0m"