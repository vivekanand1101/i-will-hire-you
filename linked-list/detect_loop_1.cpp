// Program to detect loop in a singly linked list
// using "Marking the visited node" method

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    int visited;
    struct node* next;
};

struct node* newNode(int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> data = data;
    tmp -> next = NULL;
    tmp -> visited = 0;
    return tmp;
}

// If we use this method, then we will never have a loop
// in the list because we add the new node at the end
// which would point to NULL
struct node* insert_tail(struct node* head, int data)
{
    struct node* new_node = newNode(data);
    if (head == NULL) {
        return new_node;
    }

    struct node* tmp = NULL;
    for (tmp = head; tmp -> next != NULL; tmp = tmp -> next);
    tmp -> next = new_node;
    return head;
}

// Insertion in the list. The new node is added
// to the head of the list. The last node doesn't
// point to NULL. After insertion, we point the last node
// to the head node, thus making a loop(done in main)
// This function inserts at the head
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

bool detect_loop(struct node* head)
{
    struct node* tmp = NULL;

    // Iterate over the list, marking the node
    // as visited, and if we reach a visited node,
    // then there would be a loop
    for (tmp = head; tmp != NULL; tmp = tmp -> next) {
        if (tmp -> visited == 0) {
            tmp -> visited = 1;
        } else if (tmp -> visited == 1) {
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
    head -> next -> next -> next -> next = head;
    bool loop = detect_loop(head);

    if (loop) {
        cout << "Loop detected" << endl;
    } else {
        cout << "No loop detected" << endl;
    }

    return 0;
}
