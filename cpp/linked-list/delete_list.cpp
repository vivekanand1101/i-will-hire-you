// Program to delete a list

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
    tmp -> next = NULL;
    tmp -> data = data;
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

void print_list(struct node* head)
{
    // Especially added for the case
    // of empty list
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    struct node* tmp = head;
    while(tmp) {
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }

    cout << endl;
}

// The idea is to traverse the list
// using two pointers one after the other.
// The next node is stored in one pointer
// and we free the current node, then
// update the current node
struct node* delete_list(struct node* head)
{
    if (head -> next == NULL) {
        free(head);
        return NULL;
    }

    struct node* tmp = head;
    struct node* tmp2 = head -> next;

    while(tmp2) {
        free(tmp);
        tmp = tmp2;

        // This worked!
        //cout << tmp -> data << " ";

        tmp2 = tmp2 -> next;
    }

    free(tmp); // When tmp2 has reached NULL, tmp is at the last node
    return NULL;
}

int main()
{
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    int data;
    struct node* head = NULL;

    cout << "Enter the numbers: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> data;
        head = insert(head, data);
    }

    cout << "The original list: " << endl;
    print_list(head);

    head = delete_list(head);
    cout << "The deleted list: " << endl;
    print_list(head);

    return 0;
}
