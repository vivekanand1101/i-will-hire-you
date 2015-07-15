// Program to check whether there is a loop in
// the linked list or not. The method used is
// called 'Floyd’s Cycle-Finding Algorithm'

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
    return tmp;
}

// Insertion in the list. The new node is added
// to the head of the list. The last node doesn't
// point to NULL. After insertion, we point the last node
// to the head node, thus making a loop
// And since, you have only one pointer in a
// node thus at any point if we can find a
// path which brings us to 'NULL' then obviously
// there is no loop
void insertion(struct node** head_ref, int data)
{
    struct node* tmp = newNode(data);
    if (*head_ref == NULL) {
        *head_ref = tmp;
        return;
    }

    tmp -> next = (*head_ref);
    (*head_ref) = tmp;
    return;
}

// 'Floyd’s Cycle-Finding Algorithm'
// The idea is that we start with two pointers
// starting at the head. One of the pointer is
// fast which traverses with a step of two
// nodes (skips one node everytime). The other
// pointer is normal and traverses one node in
// one iteration. Now, if there is a loop then we
// won't have any pointer which are present in
// the nodes of the list who point at 'NULL'.
// So, we either find the loop which is symbolized
// by the fact that there will be a point when these
// two pointers point at the same node or we say
// there is no loop when any of the pointers point
// to 'NULL'.
bool detect_loop(struct node* head)
{
    struct node* slow_ptr = head;
    struct node* fast_ptr = head;

    while(slow_ptr && fast_ptr && fast_ptr -> next) {
        slow_ptr = slow_ptr -> next;
        fast_ptr = fast_ptr -> next -> next;

        if (slow_ptr == fast_ptr) {
            return true;
        }
    }

    return false;
}

int main()
{
    struct node* head = NULL;
    insertion(&head, 1);
    insertion(&head, 2);
    insertion(&head, 3);
    insertion(&head, 4);

    // Creates a loop
    head -> next -> next -> next -> next = head -> next;
    bool loop = detect_loop(head);

    if (loop) {
        cout << "Loop detected" << endl;
    } else {
        cout << "No loop detected" << endl;
    }

    return 0;
}
