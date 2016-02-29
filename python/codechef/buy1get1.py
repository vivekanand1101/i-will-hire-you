from math import floor

t = int(raw_input())
for i in range(t):
    x = raw_input()
    len_ = []
    y = list(set(x))
    for j in y:
        len_.append(x.count(j))
    for j in range(len(len_)):
        if len_[j] % 2 == 0:
            len_[j] = len_[j] // 2
        else:
            len_[j] = int(len_[j] // 2) + 1
    print sum(len_)
