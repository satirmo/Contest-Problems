import random
import string

def generate_test_case_with_substring():
    substring_count = random.randint(1, 11)
    max_substring_length = int(max_superstring_length / substring_count)
    substring_length = random.randint(1, max_substring_length)
    
    substring = generate_random_string(substring_length)
    remaining_characters = max_superstring_length - substring_count * substring_length

    superstring = ''

    for i in range(substring_count):
        max_prefix_length = int(2 * remaining_characters / 3)
        prefix_length = random.randint(1, max_prefix_length) if max_prefix_length > 0 else 0
        prefix = generate_string_without_substring(prefix_length, substring)

        superstring += prefix + substring
        remaining_characters -= prefix_length
    
    superstring += generate_string_without_substring(remaining_characters, substring)

    return (superstring, substring)

def generate_test_case_with_no_substring(substring_length):
    substring = generate_random_string(substring_length)

    letters = ''.join([letter if letter in substring else '' for letter in string.ascii_uppercase])
    superstring = ''.join([random.choice(letters) for i in range(max_superstring_length)])

    while substring in superstring:
        substring = generate_random_string(substring_length)

    return (superstring, substring)

def generate_string_without_substring(length, substring):
    ret = generate_random_string(length)

    while substring in ret:
        ret = generate_random_string(length)

    return ret

def generate_random_string(length):
    letters = string.ascii_uppercase
    return ''.join(random.choice(letters) for i in range(length))

max_superstring_length = 100
test_cases = []

# generate 90 test cases in which S is a substring of T
test_cases.extend([generate_test_case_with_substring() for i in range(90)])

# generate 10 test cases in which S is a substring of T
test_cases.extend([generate_test_case_with_no_substring(i + 1) for i in range(10)])

# shuffle test cases
random.shuffle(test_cases)

# output the test cases
print(100)

for test_case in test_cases:
    s = test_case[0]
    t = test_case[1]

    print(f'{s} {t}')
