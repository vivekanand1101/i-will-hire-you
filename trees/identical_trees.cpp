// Program to check if two trees are identical or not

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

// Checks if two given trees are identical
// For the trees to be identical the data stored in
// them should be same and the left and right subtrees
// should be identical
bool identical(struct node* tree1, struct node* tree2)
{
    // Base case: when they reach a leaf
    // It is needed only when the trees have
    // been identical till now
    if (tree1 == NULL && tree2 == NULL) {
         return true;
    }

    // The if-statement is because you want to check if
    // one of the trees haven't reached the leaf node
    if (tree1 != NULL && tree2 != NULL) {
        return (tree1 -> data == tree2 -> data &&
                identical(tree1 -> left, tree2 -> left) &&
                identical(tree1 -> right, tree2 -> right));
    }

    // For the case when one of the trees have reached the leaf node
    return false;
}

int main()
{
    struct node* root1 = newNode(1);
    struct node* root2 = newNode(1);
    root1 -> left = newNode(2);
    root2-> left = newNode(2);
    root1 -> right = newNode(3);
    root2 -> right = newNode(3);
    root1 -> left -> left = newNode(4);
    root2 -> left -> left = newNode(4);
//    root2 -> right -> right = newNode(5);

    if(identical(root1, root2)) {
        cout << "Identical trees" << endl;
    } else {
        cout << "Not identical trees" << endl;
    }

    return 0;
}
