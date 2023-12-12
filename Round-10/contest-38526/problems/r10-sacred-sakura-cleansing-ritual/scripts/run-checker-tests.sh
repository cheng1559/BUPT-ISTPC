#!/usr/bin/env bash
echo "Running 2 checker test(s)"
echo "Running 2 checker test(s)" 1> checker-tests.log
echo "Running test #1" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/01 files/tests/checker-tests/01.o files/tests/checker-tests/01.a 2>> checker-tests.log
if [ "$?" -ne "1" ]; then
    echo "Checker returned incorrect verdict. Expected: Wrong answer" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: Wrong answer. See checker-tests.log for checker comment"
    read
fi
echo "Running test #2" 1>> checker-tests.log
echo "Checker comment:" 1>> checker-tests.log
wine check.exe files/tests/checker-tests/02 files/tests/checker-tests/02.o files/tests/checker-tests/02.a 2>> checker-tests.log
if [ "$?" -ne "0" ]; then
    echo "Checker returned incorrect verdict. Expected: OK" 1>> checker-tests.log
    echo "Checker returned incorrect verdict. Expected: OK. See checker-tests.log for checker comment"
    read
fi
rm -f checker-tests.log
echo "Checker test(s) finished"
