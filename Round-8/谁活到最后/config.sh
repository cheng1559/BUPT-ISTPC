# Usage: subtask <test_count> <subtask_id> <score> <minx> <maxx> <maxn> <seed>
subtask() {
	IFS=$'\n'
	for line in `$work_tmp/generator $3 $4 $5 $6`; do
		test_case $1 $2 printf $line
	done
}

subtask 0 2 10 1 1 10 cergfuewfl
subtask 1 2 10 10 3000 10 dhfireff
subtask 2 2 10 10000 1000000 10 fh8erfe34 
subtask 3 2 10 2000000 100000000 10 aatt845tt 
subtask 4 2 10 200000000 1000000000000000 10 it435ty5y6