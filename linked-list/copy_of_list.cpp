// Create a copy of a given list of size n.

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* getNode()
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    return tmp;
}

void printList(struct node* head)
{
    struct node* tmp = head;

    for (; tmp != NULL; tmp = tmp -> next) {
        cout << tmp -> data << " ";
    }

    cout << endl;
    return;
}

struct node* tailInsertion(struct node *head, int data)
{
    struct node* tmp = head;
    struct node* new_node = NULL;

    // The case of first node.
    if (head == NULL) {
        new_node = getNode();
        new_node -> data = data;
        new_node -> next = NULL;
        head = new_node;
        return head;
    }

    // If the list is not empty, traverse to the last node, point tmp to the
    // last node.
    for (; tmp -> next != NULL; tmp = tmp -> next);

    new_node = getNode();
    new_node -> data = data;
    new_node -> next = NULL;
    tmp -> next = new_node;

    return head;
}

struct node* createCopy (struct node* head, int n)
{
    struct node *tmp = head;
    int data;

    struct node* headCopy = NULL;

    // Traverse the original list for getting the data of the copied list
    for (; tmp != NULL; tmp = tmp -> next) {
        data = tmp -> data;
        headCopy = tailInsertion(headCopy, data);
    }

    return headCopy;
}

int main()
{
    int n;
    cout << "Enter number of nodes: " << endl;
    cin >> n;
    int data;
    struct node* tmp = NULL;
    struct node* head = NULL;

    cout << "Enter the data for the list: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> data;
        head = tailInsertion(head, data);
    }

    head = createCopy(head, n);
    cout << "The copied list: " << endl;
    printList(head);

    return 0;
}
