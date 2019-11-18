import random
import string

def generate_random_string(length):
    letters = 'BW'
    return ''.join(random.choice(letters) for i in range(length))

def generate_test_case(n, m):
    min_cost = int(max_cost * 9 / 10)
    c1 = random.randint(min_cost, 10000000)
    c2 = random.randint(1, 10000000)

    board = [generate_random_string(m) for i in range(n)]

    test_case = []
    test_case.append(f'{n} {m}')
    test_case.append(f'{c1} {c2}')
    test_case.extend(board)

    return test_case

max_cost = 10000000
max_side_length = 4
max_test_case_count = 200

test_cases = []

# generate test cases
for i in range(max_test_case_count):
    n = (int(i / max_side_length) % max_side_length) + 1
    m = (i % max_side_length) + 1

    test_cases.append(generate_test_case(n, m))

# shuffle test cases
random.shuffle(test_cases)

# output the test cases
test_cases_count = len(test_cases)
print(test_cases_count)

for test_case in test_cases:
    for line in test_case:
        print(line)