t = int(raw_input())

for i in range(t):
    x = map(int, raw_input().split(' '))
    n = x[0]
    m = x[1]
    y = map(int, raw_input().split(' '))

    init_jobs = [True for j in range(n)]
    for j in range(n):
        if j in y:
            init_jobs[j - 1] = False

    chef_jobs = []
    ass_jobs = []
    turn = 'chef'
    for j in range(n):
        if init_jobs[j] and turn == 'chef':
            chef_jobs.append(j + 1)
            turn = 'ass'
        elif init_jobs[j] and turn == 'ass':
            ass_jobs.append(j + 1)
            turn = 'chef'

    if chef_jobs:
        for j in chef_jobs:
            print j,

    print

    if ass_jobs:
        for j in ass_jobs:
            print j,
