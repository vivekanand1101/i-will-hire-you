t = int(raw_input())

for i in range(t):
    nc = raw_input().split(' ')
    n = int(nc[0])
    c = int(nc[1])
    x = raw_input().split(' ')
    x = map(int, x)
    sum_ = sum(x)
    if sum_ >= c:
        print 'No'
    else:
        print 'Yes'
