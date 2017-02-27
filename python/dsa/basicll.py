#!/usr/bin/env python
# coding=utf-8

import random


class Node(object):
    ''' Objects of this class will be the nodes of LL '''

    def __init__(self, data, next):
        ''' Instatiate a Node '''
        self.data = data
        self.next = next

    def __repr__(self):
        ''' Represent the node '''
        return "Data: %s" % self.data


class LinkedList(object):
    ''' A class to represent a linked list '''

    def __init__(self, head):
        ''' Instatiate a linked list '''
        self.head = head

    def insert_end(self, node):
        ''' Insert a new node in the list '''
        if self.head is None:
            self.head = node

        tmp = self.head
        while tmp.next:
            tmp = tmp.next

        tmp.next = node
        node.next = None

    def display(self):
        ''' Display the list '''

        tmp = self.head
        while tmp:
            print tmp, '->',
            tmp = tmp.next
        print 'None'

    @property
    def middle_node(self):
        ''' Return the middle node '''

        if self.head is None:
            return None

        slow_ptr, fast_ptr = self.head, self.head

        while fast_ptr and fast_ptr.next:
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next
            if fast_ptr.next:
                fast_ptr = fast_ptr.next
        return slow_ptr

    def remove_head(self):
        ''' Remove the head element '''
        if self.head is None:
            return

        # we just lost the head
        self.head = self.head.next

    def add_head(self, node):
        ''' Add a new head '''

        if self.head is None:
            self.head = node
            return
        node.next = self.head
        self.head = node

def main():
    ''' The main function '''

    data = random.randint(1, 10000)
    node = Node(data, None)
    print "Root is %s" % data
    linked_list = LinkedList(node)

    # Let's add a few nodes
    for i in range(4):
        data = random.randint(1, 10000)
        node = Node(data=data, next=None)
        linked_list.insert_end(node)
    linked_list.display()

    # Let's find the middle node
    middle_node = linked_list.middle_node
    print "The middle node is %s" % middle_node

    # Let's remove the head
    linked_list.remove_head()
    print "Removed the head: "
    linked_list.display()

    # Let's add a new head
    data = random.randint(1, 10000)
    node = Node(data, None)
    linked_list.add_head(node)
    print "Add a new head: %s" % node
    linked_list.display()

if __name__ == '__main__':
    main()
