// Program to find the minimum value in a binary search tree
// The max value can be found out in the same way
// Just traverse to the rightmost node

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Returns a pointer to the new node with data in it
struct node* newNode(int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> data = data;
    tmp -> left = NULL;
    tmp -> right = NULL;
}

// Inserts in the binary search tree
// See the comments in basic_traversals.cpp
// for details.
struct node* insert_bst(struct node* tree, int data)
{
    if (tree == NULL) {
        struct node* tmp = newNode(data);
        return tmp;
    }

    if (data > tree -> data) {
        tree -> right = insert_bst(tree -> right, data);
        return tree;
    } else if (data < tree -> data) {
        tree -> left = insert_bst(tree -> left, data);
        return tree;
    }
}

// Since, it is a bst, so
// the minimum value is the data
// stored in the leftmost node
// of the tree
int minValue(struct node* tree)
{
    // Reach the leftmost node in the tree
    if (tree -> left != NULL) {
        return minValue(tree -> left);
    }

    // Return the data in the leftmost
    // node of the tree
    return tree -> data;
}

int main()
{
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;
    struct node* tree = NULL;
    int min_val;
    int data;

    cout << "Enter the numbers: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> data;
        tree = insert_bst(tree, data);
    }

    // This if statement checks for the case
    // when the user inputs 0 as the number of
    // nodes. If it were not present, then we
    // would have segmentation fault, due to
    // accessing the left pointer of the tree
    // in the minValue function.
    if (tree != NULL) {
        min_val = minValue(tree);
        cout << "The minimum value in the tree is: " << min_val << endl;
    } else {
        cout << "No data in the tree" << endl;
    }

    return 0;
}
