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


print edit_distance_recur(str1, str2)
