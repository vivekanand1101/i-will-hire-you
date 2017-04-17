#!/usr/bin/env python
# coding=utf-8

str1 = "sunday"
str2 = "saturday"


def edit_distance_recur(str1, str2):
    ''' Returns the edit distance of the two strings '''

    m = len(str1)
    n = len(str2)

    if 0 in [m, n]:
        return max(m, n)

    if str1[-1] == str2[-1]:
        return edit_distance_recur(str1[:-1], str2[:-2])

    insert_cost = 1 + edit_distance_recur(str1, str2[:-1])
    remove_cost = 1 + edit_distance_recur(str1[:-1], str2)
    replace_cost = 1 + edit_distance_recur(str1[:-1], str2[:-1])

    return min(insert_cost, remove_cost, replace_cost)


def edit_distance(str1, str2):
    ''' Returns the edit distance of the two strings '''

    m = len(str1)
    n = len(str2)

    E = [[0 for x in range(n+1)] for i in range(m+1)]

    for i in range(m+1):
        for j in range(n+1):
            if 0 in [i, j]:
                E[i][j] = max(i, j)
            elif str1[i-1] == str2[j-1]:
                E[i][j] = E[i-1][j-1]
            else:
                E[i][j] = 1 + min(
                    E[i][j-1], E[i-1][j], E[i-1][j-1])
    return E[m][n]


print edit_distance_recur(str1, str2)
print edit_distance(str1, str2)
