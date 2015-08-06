x = raw_input()
x = x.split(' ')
x = map(int, x)
k = x[0]
n = x[1]
w = x[2]

total = 0
while (w):
    total = total + w * k
    w = w - 1

if n > total:
    print 0
else:
    print total - n
