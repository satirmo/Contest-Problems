import random
import string

def generate_random_string(length):
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for i in range(length))

def generate_small_test_cases(max_test_case_length):
    ret = []
    test_cases = [[[]]]

    for i in range(1, max_test_case_length + 1):
        test_cases.append([])

        for test_case in test_cases[i-1]:
            test_cases[i].append(test_case + [pancakesString])
            test_cases[i].append(test_case + [questionString])
            test_cases[i].append(test_case + [generate_random_string(max_string_length)])

        ret.extend(test_cases[i])

    return ret

def generate_large_test_cases(test_case_length):
    test_case = []
    random_string = generate_random_string(max_string_length)

    while random_string == pancakesString:
        random_string = generate_random_string(max_string_length)

    for i in range(test_case_length):
        option = random.randint(1, 3)

        if option == 1:
            test_case.append(pancakesString)

        elif option == 2:
            test_case.append(questionString)

        else:
            test_case.append(random_string)

    return test_case

max_test_case_count = 500
max_test_case_length = 100000
max_string_length = 3
pancakesString = 'pancakes'
questionString = '?'

# generate small test cases
test_cases = generate_small_test_cases(5)

# generate large test cases
remaining_test_cases_count = max_test_case_count - len(test_cases)
test_cases.extend([generate_large_test_cases(max_test_case_length) for i in range(remaining_test_cases_count)])

# shuffle test cases
random.shuffle(test_cases)

# output the test cases
test_cases_count = len(test_cases)
print(test_cases_count)

for test_case in test_cases:
    n = len(test_case)
    l = random.randint(1, int((n+1)/2))

    print(n, l)
    print(' '.join(test_case))