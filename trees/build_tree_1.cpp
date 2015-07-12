// Program to build an unique tree using preorder and inorder traversals

/*
1)Pick an element from Preorder. Increment a Preorder Index Variable
    (preIndex in below code) to pick next element in next recursive call.
2) Create a new tree node tNode with the data as picked element.
3) Find the picked element’s index in Inorder. Let the index be inIndex.
4) Call buildTree for elements before inIndex and make the built tree
    as left subtree of tNode.
5) Call buildTree for elements after inIndex and make the built tree
    as right subtree of tNode.
6) return tNode.
*/

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

int search(int* inorder, int inStr, int inEnd, int data)
{
    for(int i = inStr; i <= inEnd; i++) {
        if (inorder[i] == data) {
            return i;
        }
    }
}

struct node* build_tree(int* inorder, int* preorder, int inStr, int inEnd)
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

    int inIndex = search(inorder, inStr, inEnd, new_node -> data);

    new_node -> left = build_tree(inorder, preorder, inStr, inIndex - 1);
    new_node -> right = build_tree(inorder, preorder, inIndex + 1, inEnd);

    return new_node;
}

// As the name suggests, prints the tree in inorder traversal
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
    int inorder[n]; // For storing the inorder traversal data
    int preorder[n]; // For storing the preorder traversal data
    struct node* tree = NULL;

    cout << "Enter the inorder traversal: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    cout << "Enter the preorder traversal: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    // build_tree returns the root of the tree
    // after the tree has been formed from the given 
    // two arrays.
    tree = build_tree(inorder, preorder, 0, n - 1);

    cout << "The unique tree in inorder traversal: " << endl;
    print_tree_inorder(tree);
    cout << endl;

    return 0;
}
