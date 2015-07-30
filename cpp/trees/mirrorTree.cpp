// Program to make a mirror tree of the given tree
// (Simple swaping of left and right subtree through out the tree)

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> data = data;
    tmp -> left = NULL;
    tmp -> right = NULL;
    return tmp;
}

// Prints the tree in 'inorder' traversal
void printTree(struct node* tree)
{
    if (tree == NULL) {
        return;
    }

    printTree(tree -> left);
    cout << tree -> data << " ";
    printTree(tree -> right);
}

// Function to make the mirror of a given
// tree. The idea is to swap the pointers
// pointing to the left and right subtrees
// throughout the tree
// We start this swaping from the leaf node
// from the left subtree, should work if we
// tried from the right subtree(not checked)
void mirror(struct node* tree)
{
    if (tree == NULL) {
        return;
    }

    mirror(tree -> left);
    mirror(tree -> right);

    struct node* tmp = NULL;
    tmp = tree -> left;
    tree -> left = tree -> right;
    tree -> right = tmp;
//    free(tmp); (I don't know why it is not working when i free the ptr)
    return;
}

int main()
{
    struct node* tree = newNode(1);
    tree -> left = newNode(2);
    tree -> right = newNode(3);
    tree -> left -> left = newNode(4);
    tree -> left -> right = newNode(5);

    cout << "The original tree (inorder): " << endl;
    printTree(tree);
    cout << endl;

    mirror(tree);
    cout << "The mirror tree (inorder): " << endl;
    printTree(tree);
    cout << endl;

    return 0;
}
