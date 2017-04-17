#!/usr/bin/env python
# coding=utf-8


def lis(arr):
    ''' Find the longest increasing subsequence '''

    n = len(arr)

    # Initialize for each element as one
    l = [1] * n

    for i in range(n):
        for j in range(i):
            if arr[i] > arr[j] and l[i] < l[j] + 1:
                l[i] += 1

    return max(l)

arr = [10, 22, 9, 33, 21, 50, 41, 60]
print "Length of lis is", lis(arr)
