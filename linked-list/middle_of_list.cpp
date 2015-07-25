// Program to find the middle of the
// linked list

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* newNode(int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> data = data;
    tmp -> next = NULL;
}

// Tail insertion
struct node* insert(struct node* head, int data)
{
    struct node* new_node = newNode(data);

    if (head == NULL) {
        return new_node;
    }

    struct node* tmp = head;
    for (; tmp -> next != NULL; tmp = tmp -> next);

    tmp -> next = new_node;
    return head;
}

// The idea is that we traverse using two
// pointers which starts at the head.
// One of them traverses at twice the pace
// than that of the other so, when the fast
// pointer reaches the end of the list
// the slower one is still in the middle
struct node* find_middle(struct node* head)
{
    struct node* fast_ptr = head;
    struct node* slow_ptr = head;

    while(fast_ptr != NULL and fast_ptr -> next != NULL) {
        fast_ptr = fast_ptr -> next -> next;
        slow_ptr = slow_ptr -> next;
    }

    return slow_ptr;
}

int main()
{
    int n;
    cout << "Enter no of nodes: " << endl;
    cin >> n;

    if (n < 2) {
        cout << "Number of nodes should not be less than 2" << endl;
        exit(1);
    }

    int data;
    struct node* head = NULL;

    cout << "Enter the numbers: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> data;
        head = insert(head, data);
    }

    struct node* middle = NULL;
    middle = find_middle(head);

    cout << "The data of the middle node is: " << endl;
    cout << middle -> data << endl;;

    return 0;
}
