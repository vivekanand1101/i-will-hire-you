// Program to build an unique tree using preorder and inorder traversals

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
}

struct node* build_tree(int* inorder, \
                                    int* preorder, int* inStr, int* inEnd)
{
    static int preIndex = 0;

    if (inStr > inEnd) {
        return NULL;
    }

    struct node* new_node = newNode(preorder[preIndex]);
    preIndex++;

    if (inStr == inEnd) {
        return new_node;
    }

    int inIndex = search(inorder, inStr, inEnd, new_node -> data
void print_tree_inorder(struct node* tree)
{
    if (tree == NULL) {
        return;
    }

    print_tree_inorder(tree -> left);
    cout << tree -> data << " ";
    print_tree_inorder(tree -> right);
}

int main()
{
    int n;
    cout << "Enter no of nodes: "<< endl;
    cin >> n;
    int inorder[n];
    int preorder[n];
    struct node* tree = NULL;

    cout << "Enter the inorder traversal: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    cout << "Enter the preorder traversal: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    tree = build_tree(tree, inorder, preorder, 0, 0);

    cout << "The unique tree in inorder traversal: " << endl;
    print_tree_inorder(tree);
    cout << endl;

    return 0;
}
