#!/usr/bin/env python
# coding=utf-8

COST = [[1, 2, 3], [4, 8, 2], [1, 5, 3]]
INF = 100000

def min_cost(r, c):
    ''' Minimum cost to reach (r, c) from 0, 0 '''

    low_cost = [[INF]*(c+1) for i in range(r+1)]
    for i in range(r+1):
        for j in range(c+1):
            if i == 0 and j == 0:
                low_cost[i][j] = COST[i][j]

            # can only traverse down, right and diagonally lower
            elif i == 0:
                low_cost[i][j] = low_cost[i][j-1] + COST[i][j]
            elif j == 0:
                low_cost[i][j] = low_cost[i-1][j] + COST[i][j]
            else:
                low_cost[i][j] = COST[i][j] + min(
                        low_cost[i-1][j], low_cost[i][j-1], low_cost[i-1][j-1])
    return low_cost[r][c]


print min_cost(2, 2)
