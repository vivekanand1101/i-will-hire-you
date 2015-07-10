// Program to find the max depth of a tree

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Returns a newNode
struct node* newNode(int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> data = data;
    tmp -> left = NULL;
    tmp -> right = NULL;
    return tmp;
}

// Depth of the tree would be max depth of the left
// and right subtrees + 1
// Here basically, we reach the leaf and then start
// the count for the depth.
// For the case when we want to make the root to be at 0th
// height, we can change the base case return value to -1
int depth(struct node* tree)
{
    if (tree == NULL) {
        return 0;
    }

    return (max(depth(tree -> left), depth(tree -> right)) + 1);
}

int main()
{
    struct node* tree = newNode(1);
    tree -> left = newNode(2);
    tree -> right = newNode(3);
    tree -> left -> left = newNode(4);
    tree -> left -> right = newNode(5);
    tree -> right -> left = newNode(6);

    cout << "The depth of the tree is: " << endl;
    cout << depth(tree) << endl;

    return 0;
}
