# http://codeforces.com/problemset/problem/344/A

test_cases = int(raw_input())

no_of_groups = 0
for i in range(test_cases):
    x = int(raw_input())
    if i is 0:
        no_of_groups += 1
        previous = x
        continue
    elif x != previous:
        no_of_groups += 1

    previous = x

print no_of_groups
