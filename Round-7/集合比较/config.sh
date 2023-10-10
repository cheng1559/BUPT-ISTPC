# Easy subtask
test_case 0 57 printf "0\n0" # =
test_case 0 57 printf "2 1 2\n1 1" # >
test_case 0 57 printf "2 1 3\n1 2" # .
test_case 0 57 printf "0\n3 1 2 12" # <
test_case 0 57 printf "2 4 10\n0" # >
test_case 0 57 printf "2 4000 100000000\n2 4000 100000000" # =
test_case 0 57 printf "2 4000 99999999\n2 4000 100000000" # .
test_case 0 57 ./generator equals 5 5 3435831294 # =
test_case 0 57 ./generator none 5 5 3147538944 # .
test_case 0 57 ./generator x_contains_y 5 4 1288372093 # >

# Hard subtask
test_case 1 4 ./generator x_contains_y 1000 999 65387386812 # .
test_case 1 4 ./generator y_contains_x 999 1000 42578452017 # .
test_case 1 4 ./generator equals 1000 1000 1242848283 # =
test_case 1 4 ./generator none 1000 1000 24564566543 # .
test_case 1 4 ./generator none 892 319 4257857823 # .
test_case 1 4 ./generator x_contains_y 343 328 65387386812 # .
test_case 1 4 ./generator y_contains_x 478 892 42578452017 # .
test_case 1 5 ./generator equals 984 984 1242848283 # =
test_case 1 5 ./generator none 412 438 24564566543 # .
test_case 1 5 ./generator none 833 314 4257857823 # .


# Assertions
reject wrong_sol/compare_string.py # This program attempt to compare string instead of set
reject wrong_sol/forgot_to_strip_the_first.py # This program forgot to strip the first number
reject wrong_sol/compare_only_length.py # This program attempt to compare only the length