// Program to delete all the nodes of a binary tree

#include <iostream>
#include <cstdlib>

using namespace std;

// Represents a node in the tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Returns a pointer to the new node with the
// given data stored in it
struct node* newNode(int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> data = data;
    tmp -> left = NULL;
    tmp -> right = NULL;
}

// The idea is that we traverse the tree
// in postorder traversal so that we can
// reach the children before the parents
void deleteTree(struct node* tree)
{
    if (tree == NULL) {
        return;
    }

    deleteTree(tree -> left);
    deleteTree(tree -> right);
    cout << "About to get freed: " << tree -> data << endl;
    free(tree); // Free the memory pointed by the pointer
}

int main()
{
    struct node* tree = newNode(1);
    tree -> left = newNode(2);
    tree -> right = newNode(3);
    tree -> left -> left = newNode(4);
    tree -> right -> left = newNode(5);

    deleteTree(tree);
    return 0;
}    
