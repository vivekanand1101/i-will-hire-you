class Node:
    """The objects of this class are
        nodes of the tree
    """
    def __init__(self, data):
        self.data = data

        #These two will be reference to
        #object of class 'Node'
        self.left = None
        self.right = None

class Tree:
    """This class represents a tree"""

    def create_node(self, data):
        """Creates a node of the tree returns
            a reference to that node object
        """
        return Node(data)

    def insert(self, node , data):
        """
        Insert function will insert a node into tree.
        Duplicate keys are not allowed.
        """
        #if tree is empty , return a root node
        if node is None:
            return self.create_node(data)

        # if data is smaller than parent,
        # insert it into left side
        if data < node.data:
            node.left = self.insert(node.left, data)

        #if we use elif here, repeated data won't get stored
        else:
            node.right = self.insert(node.right, data)

        return node

    def inorder(self, node):
        """Inorder tree traversal"""

        if node is None:
            return
        self.inorder(node.left)
        print node.data,
        self.inorder(node.right)

    def postorder(self, node):
        """Postorder tree traversal"""

        if node is not None:
            self.postorder(node.left)
            self.postorder(node.right)
            print node.data,

    def preorder(self, node):
        """Preorder tree traversal"""

        if node is not None:
            print node.data,
            self.preorder(node.left)
            self.preorder(node.right)

def main():

    #initialize the root,
    #will be an object of
    #class 'Node' later
    root = None
    #tree object
    tree = Tree()

    #can enter any number of nodes
    #but has to be on the same line
    print "Enter all the data to be stored in a line: "
    data = raw_input()

    #making the data to be an int
    #raw_input returs a string
    #an error will occur if we put
    #space after the last element
    data = data.split(' ')
    [int(i) for i in data]

    #insert in the tree all the
    #data initially taken
    for i in data:
        root = tree.insert(root, i)

    print "Inorder: "
    tree.inorder(root)
    print

    print "Preorder: "
    tree.preorder(root)
    print

    print "Postorder: "
    tree.postorder(root)
    print

    print 'Attributes: '
    print dir(tree)
    print

if __name__ == '__main__':
    main()
