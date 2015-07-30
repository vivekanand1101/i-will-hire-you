// Program to create a linked list which
// inserts elements in sorted order

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

void* print_list(struct node* head)
{
    struct node* tmp = head;

    for (; tmp != NULL; tmp = tmp -> next) {
        cout << tmp -> data << " ";
    }

    cout << endl;
}

struct node* sorted_insert(struct node* head, int data)
{
    struct node* new_node = newNode(data);

    if (head == NULL) {
        return new_node;
    }

    struct node* tmp = head;
    struct node* tmp2 = NULL;

    for (; tmp != NULL && new_node -> data > tmp -> data;) {

        if (tmp2 == NULL) {
            tmp2 = head;
        }

        tmp2 = tmp;
        tmp = tmp -> next;
    }

    if (tmp2 == NULL) {
        new_node -> next = head;
        head = new_node;
        return head;
    }

    new_node -> next = tmp2 -> next;
    tmp2 -> next = new_node;

    return head;
}

int main()
{
    int n;
    cout << "Enter number of nodes: " << endl;
    cin >> n;

    int data;

    struct node* head = NULL;
    cout << "Enter the data: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> data;
        head = sorted_insert(head, data);
    }

    print_list(head);

    return 0;
}
