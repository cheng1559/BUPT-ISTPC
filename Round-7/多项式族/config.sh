# Easy subtask
test_case 0 57 ./generator yes 23 # f(x) = 23
test_case 0 57 ./generator yes 1 7 # f(x) = 1 + 7 * x
test_case 0 57 ./generator yes 5 2/3 # f(x) = 5 + 2 * x
test_case 0 57 ./generator no 3 3/5 # f(x) = 3 + 3 * x
test_case 0 57 ./generator no 0 11/2 # f(x) = 0 + 11/2 * x

# Hard subtask
test_case 1 8 ./generator yes 2 1/2 2/3 0 0 1/216 0 1/559872 1/559872
test_case 1 8 ./generator yes 7 1/3 2/3 2/27 0 1/9 0 5/27 1/27
test_case 1 9 ./generator no 1 1/2 1/2 0 0 0 0 0 1/2048
test_case 1 9 ./generator yes 0 1/5 1/5 2/25
test_case 1 9 ./generator yes 0 1/3 1/3 2/49

reject wrong_sol/always_yes.py
reject wrong_sol/infinity.py