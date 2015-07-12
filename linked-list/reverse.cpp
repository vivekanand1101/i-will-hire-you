// Program to reverse a linked list iteratively

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

// Insert an item at the end of the list
// This ensures that the list created is in the
// same order as was the input. If it was created
// using insert_head then it would have appeared to
// have inserted in the reverse order
struct node* insert_tail(struct node* head, int data)
{
    struct node* tmp = head;

    // During the insertion of the first node
    if (tmp == NULL) {
        head = newNode(data);
        return head;
    }

    // During insertion when the list is not empty
    struct node* new_node = newNode(data);

    // Traverse the list to the end
    // Let the tmp point to the last node
    for (tmp = head; tmp -> next != NULL; tmp = tmp -> next);

    // Once the tmp points to the last node
    // insert the new node after the last node
    tmp -> next = new_node;

    // It should not be tmp because, tmp is pointing to the last
    // node at this moment
    return head;
}

// Reverses the list and returns the pointer to
// the new head
// The idea is to place two new pointers:
// one with the head of the original list
// and the other as the head the reversed list
// After reversing, just return the head of the
// reversed list
struct node* reverse_list(struct node* head)
{
    struct node* tmp = head; // tmp pointing to the original list
    struct node* tmpRev = NULL; // head of the reversed list

    // run the loop untill all the elements are finished
    while (head) {
        head = head -> next;// step is valid, since tmp is pointing to the node
        tmp -> next = tmpRev;//This step transfers the node to the reversed list
        tmpRev = tmp;//Place the head of the reversed list at its new position
        tmp = head;// tmp goes back to the original list
    }

    head = tmpRev; // Assign the new reversed head to head
    return head;
}

void printList(struct node* head)
{
    // so that the position of head doesn't change during printing
    struct node* tmp = head;
    for (; tmp != NULL; tmp = tmp -> next) {
        cout << tmp -> data << " ";
    }

    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;
    int data;
    struct node* head = NULL;

    cout << "Enter the numbers to be stored: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> data;
        head = insert_tail(head, data);
    }

    cout << "The original list: " << endl;
    printList(head);

    head = reverse_list(head);

    cout << "The reversed list: " << endl;
    printList(head);

    return 0;
}
