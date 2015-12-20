n = int(raw_input())
X = map(int, raw_input().split(' '))
p = X[0]
Y = map(int, raw_input().split(' '))
q = Y[0]

X, Y = set(X[1:]), set(Y[1:])

tmp_set = set()
for i in range(1, n + 1):
    tmp_set.add(i)

if X.union(Y) == tmp_set:
    print 'I become the guy.'
else:
    print 'Oh, my keyboard!'
