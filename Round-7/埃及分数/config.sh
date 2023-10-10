# Easy subtask
test_case 0 57 printf "3\n2 4 30"
test_case 0 57 ./generator conm 12
test_case 0 57 ./generator pow2 12
test_case 0 57 ./generator pow3 7
test_case 0 57 ./generator rand 12

# Hard subtask, use seed
test_case 1 8 ./generator rand 50 3020826194
test_case 1 8 ./generator rand 45 2877829739
test_case 1 9 ./generator rand 36 0327218407
test_case 1 9 ./generator rand 44 2877829739
test_case 1 9 ./generator rand 47 0327218407

# Assertions
reject wrong_sol/print_identical_input.py # This program attempt to copy the input to the output
reject wrong_sol/split_the_first.py # This program attempt to split the first number
reject wrong_sol/divide_last_by_2.py # This program attempt to divide the last number by 2
reject wrong_sol/use_float.py # This program attempt to use float instead of fraction
reject wrong_sol/use_short_array.py # This program attempt to use array that is too short
reject wrong_sol/output_huge_integer.py # This program attempt to output a huge integer that is not in the range