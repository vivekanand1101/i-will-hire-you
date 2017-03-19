#!/usr/bin/env python
# coding=utf-8

# d[lengthofpiece] = cost of the piece
table = {'1': 1, '2': 5, '3': 8, '4': 9, '5': 10, '6': 17, '7': 17, '8': 20}

# find the best cost we can get by cutting rod of length n, where n = 8 here

n = 8
best_cost = {}

for i in range(1, n + 1):
    dp_cost = []
    for j in range(1, i + 1):
        cost = table[str(j)]
        dp_cost.append(cost + best_cost.get(str(i-j), 0))
    best_cost[str(i)] = max(dp_cost)
print best_cost[str(n)]
