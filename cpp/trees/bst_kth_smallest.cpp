// Program to find the kth smallest
// element in the tree

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode (int data)
{
    struct node* tmp = (struct node*) malloc(sizeof(struct node));
    tmp -> data = data;
    tmp -> right = NULL;
    tmp -> left = NULL;
}

struct node* insert_bst (struct node* head, int data)
{

    if (head == NULL) {
        struct node* new_node = newNode(data);
        return new_node;
    }

    if (data < head -> data) {
        head -> left = insert_bst(head -> left, data);
        return head;
    } else {
        head -> right = insert_bst (head -> right, data);
        return head;
    }

}

// The idea is simple, for the
// smallest element, you go to
// the leftmost element, and similarly
// to the rightmost for the maximum.
// Thus, if we have to go for kth,
// the traversal should be somewhat
// form left to right which is given
// by inorder traversal. In this traversal,
// you print in sorted order, so if we
// put some constraint here, then we can
// definitely check for some kth element.
void print_tree (struct node* head, int k)
{
    if (head != NULL) {
        print_tree (head -> left, k);

        static int target = 0;
        target++;

        if (target == k) {
            cout << "The kth smallest number is: "  << head -> data << " ";
        }

        print_tree (head -> right, k);
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes: " << endl;
    cin >> n;

    struct node* head = NULL;
    int data;

    for (int i = 0; i < n; i++) {
        cin >> data;
        head = insert_bst(head, data);
    }
    
    cout << "Enter the value of k: " << endl;
    int k;
    cin >> k;

    print_tree(head, k);
    cout << endl;

    return 0;
}
