// Program to find the majority element if present in the
// given sequence. Majority element is the element which
// occurs more than or n/2 times in the sequence of n elements
// This was just for fun. This method is not good at all
// The idea is to have a field "count" in each of the node
// and counting the number of instances in the sequence, if
// the number exceeds n / 2 then it is the majority element.

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    int count; // Field for keeping count of a number in the sequence
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> left = NULL;
    tmp -> right = NULL;
    tmp -> data = data;
    return tmp;
}

struct node* insert_bst_search_majority(struct node* head, int data, int n)
{
    struct node* new_node = newNode(data);

    // Base case
    if (head == NULL) {
        new_node -> count = 1;

        // If the sequence has only 1 node and he is searching
        // for majority element.
        if (n == 1) {
            cout << "You are mad" << endl;
        }

        return new_node;
    }

    // This is an additional step, normally
    // not present in bst. It just increases
    // the count
    // For other details, see basic traversals
    // in tree folder only

    if (head -> data == new_node -> data) {
        head -> count = head -> count + 1;
        if (head -> count > n / 2) {
            cout << "Majority element is: " << head -> data << endl;
            exit(1);
        }

        free(new_node);
        return head;
    } else if (new_node -> data < head -> data) {
        head -> left = insert_bst_search_majority(head -> left, data, n);
        return head;
    } else if (new_node -> data > head -> data) {
        head -> right = insert_bst_search_majority(head -> right, data, n);
        return head;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the sequence" << endl;
    cin >> n;

    int data;
    struct node* head = NULL;

    cout << "Enter the elments: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> data;
        head = insert_bst_search_majority(head, data, n);
    }

    cout << "No majority element" << endl;
    return 0;
}
