// Program to delete a node, the only pointer
// which is given to you is the pointer pointing
// to that node
// The below solution doesn't work if the
// node to be deleted is the last node
// of the tree

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* getNode(int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node*));
    tmp -> data = data;
    tmp -> next = NULL;
}

// Tail insertion
struct node* insert (struct node* head, int data)
{
    struct node* new_node = getNode(data);

    if (head == NULL) {
        return new_node;
    }

    struct node* tmp = NULL;

    for (tmp = head; tmp -> next != NULL; tmp = tmp -> next);

    tmp -> next = new_node;
    return head;
}

// The solution doesn't work is the
// node to be deleted is the last node
// of the list because, in the solution
// it exchanges data from the next node
// and then deletes the next node
void delete_pointed_node(struct node* tmp)
{
    // if the next node is null,
    // then we won't be able to extract
    // data from the next node
    if (tmp -> next != NULL) {
        // Variables to store data
        // from the two nodes
        int node_data;
        int next_node_data;

        node_data = tmp -> data;
        next_node_data = tmp -> next -> data;

        // Exchange the data of the two nodes
        tmp -> next -> data = node_data;
        tmp -> data = next_node_data;

        // Delete the node
        tmp -> next = tmp -> next -> next;
    }
}

void print_list(struct node* head)
{
    struct node* tmp = head;
    while(tmp) {
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }

    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of nodes: " << endl;
    cin >> n;
    int data;
    int position;

    struct node* head = NULL;
    cout << "Enter the data: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> data;
        head = insert(head, data);
    }

    cout << "The original list: " << endl;
    print_list(head);

    // Creating the question
    // We are creating a pointer
    // which would be pointing
    // to the specified position
    // The position starts from 1 not 0
    cout << "Enter the position of node whose data is to be deleted: " << endl;
    cin >> position;

    if (position == n) {
        cout << "Can't delete the last node" << endl;
        exit(1);
    }

    struct node* tmp = head;
    for (int i = 1; i < position; i++) {
        tmp = tmp -> next;
    }

    delete_pointed_node(tmp);

    cout << "The new list: " << endl;
    print_list(head);

    return 0;
}
