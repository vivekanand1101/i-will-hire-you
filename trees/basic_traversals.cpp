// Make a Binary search tree, print it using inorder, postorder, preorder

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node* left; // pointer to left subtree
    struct node* right; // pointer to right subtree
};

// Returns a pointer to the node containing the req data
struct node* getNode(int data)
{
    struct node* tmp = (struct node* ) malloc(sizeof(struct node));
    tmp -> data = data;

    return tmp;
}

// Inserts a node in  the tree with a given data.
// Condition: data in left sub-tree < data in right sub-tree
// In the recur call of insert(), if we had returned the
// corresponding left or right pointers then we would have
// ended up with a reference to the inserted node in head (next iter).
struct node* insert(struct node* head, int data)
{

    if (head == NULL) {
        struct node* tmp = getNode(data);
        return tmp;
    }

    if (data < head -> data) {
        head -> left = insert(head -> left, data);
        return head;
    } else if (data > head -> data) {
        head -> right = insert(head -> right, data);
        return head;
    }
}

// Prints the inorder traversal of the tree - left - root -right
void inorder(struct node* head)
{
    if (head == NULL) {
        return;
    }

    inorder(head -> left);
    cout << head -> data << " ";
    inorder(head -> right);
}

// Prints the preorder traversal of the tree - root - left - right
void preorder(struct node* head)
{
    if (head == NULL) {
        return;
    }

    cout << head -> data << " ";
    preorder(head -> left);
    preorder(head -> right);
}

// Prints the postorder traversal of the tree - left - right - root
void postorder(struct node* head)
{
    if (head == NULL) {
        return;
    }

    postorder(head -> left);
    postorder(head -> right);
    cout << head -> data << " ";
}

int main()
{
    int n;
    int data;
    cout << "Enter no of nodes: " << endl;
    cin >> n;

    // Initialize the pointer to the root of the tree
    struct node* head = NULL;
    cout << "Enter the data to be entered in the nodes: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> data;
        head = insert(head, data);
    }

    cout << "Inorder traversal: " << endl;
    inorder(head);
    cout << endl;


    cout << "Postorder traversal: " << endl;
    postorder(head);
    cout << endl;

    cout << "Preorder traversal: " << endl;
    preorder(head);
    cout << endl;

    return 0;
}
