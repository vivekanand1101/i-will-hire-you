#!/usr/bin/env python
# coding=utf-8

str1 = 'AGGTAB'
str2 = 'GXTXAYB'

n = max(len(str1), len(str2))

def lcs(str1, str2):
    ''' Find the lcs of two given strings '''

    m = len(str1)
    n = len(str2)
    if 0 in [m, n]:
        return 0

    L = [[None] * (n+1) for i in range(m+1)]
    for i in range(m+1):
        for j in range(n+1):
            if 0 in [i, j]:
                L[i][j] = 0
            elif str1[i-1] == str2[j-1]:
                L[i][j] = L[i-1][j-1] + 1
            else:
                L[i][j] = max(L[i-1][j], L[i][j-1])

    return L[m][n]

print lcs(str1, str2)
