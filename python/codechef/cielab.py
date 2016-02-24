x = raw_input().split(' ')
a = int(x[0])
b = int(x[1])

ans = a - b
k = ans % 10
if k == 9:
    ans = ans - 1
else:
    ans = ans + 1
print ans
