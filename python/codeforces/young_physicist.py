# http://codeforces.com/contest/69/problem/A
# This code is not working and i don't have
# any idea why. It gives runtime error on 7th
# test case

n = int(raw_input())
l = [raw_input() for i in range (n)]
l = [i.split(' ') for i in l]

for i in range (n):
    total = 0
    flag = 1

    for j in range (n):
        total = total + int(l[j][i])

    if total != 0:
        flag = 0
        break

if flag == 0:
    print 'NO'
else:
    print 'YES'
