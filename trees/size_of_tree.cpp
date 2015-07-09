// Program to calculate the size of a given tree

#include <iostream>
#include <cstdlib>

using namespace std;

// Represents the a node of the tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Returs a pointer to a new node with the passed data in it
struct node* newNode(int data)
{
    struct node* tmp = (struct node*) malloc(sizeof(struct node));
    tmp -> data = data;
    return tmp;
}

// Function to calculate the size of the tree
// The logic is that the size of the tree is one more
// than the sum of the sizes of the left subtree and
// the right subtree
// The 'plus 1' can be put anywhere between the recursive calls
// ^Just think about the last node - it would always return 1
// irrespective of the placement of the '1'
int size(struct node* head)
{
    if (head == NULL) {
        return 0;
    }

    return 1 + size(head -> left) + size(head -> right);
}

int main()
{
    struct node* head = newNode(1);
    head -> left = newNode(2);
    head -> right = newNode(3);
    head -> left -> left = newNode(4);
    head -> left -> right = newNode(5);

    cout << "The size of the tree is: " << endl;
    cout << size(head) << endl;

    return 0;
}
