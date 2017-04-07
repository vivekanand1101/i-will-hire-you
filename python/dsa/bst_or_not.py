#!/usr/bin/env python
# coding=utf-8

# Python program to check if a binary tree is bst or not

# A binary tree node
class Node:

    # Constructor to create a new node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def isBST(root, v):
    ''' Traverse inorder and if not sorted, it's not bst then '''

    if root is None:
        return []

    v = isBST(root.left, v)
    v.append(root.data)
    v = isBST(root.right, v)
    return v


# Driver program to test above function
root = Node(4)
root.left = Node(2)
root.right = Node(5)
root.left.left = Node(1)
root.left.right = Node(3)

v = isBST(root, [])

if v == sorted(v):
    print "Is BST"
else:
    print "Not a BST"
