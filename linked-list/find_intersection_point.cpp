// Program to find the intersection point of two
// linked lists. Input is head pointers to both
// the lists and output would be the data stored
// in the node which is the point of intersection

// The idea is to first find which one of the linked
// list is larger, then we first traverse the larger
// linked list "d" nodes where d is the difference
// between the number of nodes of the two lists
// And then the two lists are traversed parallely
// untill the pointers point to the same node, which
// is the intersection point.

// Remember that in this method we assume that
// there is a loop present and we are testing
// here on such a single case only

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
    return tmp;
}

// Gives count of the number of nodes in
// the list - given the head of the node
int getNumberOfNodes(struct node* head)
{
    int count = 0;
    struct node* tmp = head;

    while(tmp) {
        count++;
        tmp = tmp -> next;
    }

    return count;
}

// Once decided that which one of the list is bigger,
// this function is called for finding the intersection
// point. Read comment at the top for more clarification
struct node* _getIntersectionNode(struct node* larger, struct node* smaller, \
                                    int diff)
{
    for (; diff != 0; diff--) {
        larger = larger -> next;
    }

    while(larger != smaller) {
        larger = larger -> next;
        smaller = smaller -> next;
    }

    return larger;
}

// Decides which one is the larger node and eventually
// calls the _getIntersectionNode with the correct
// order of larger and smaller lists
struct node* getIntersectionNode(struct node* head1, struct node* head2)
{
    int count1 = getNumberOfNodes(head1);
    int count2 = getNumberOfNodes(head2);

    int diff = abs(count1 - count2);
    if (count1 < count2) {
        return _getIntersectionNode(head2, head1, diff);
    } else {
        return _getIntersectionNode(head1, head2, diff);
    }
}

/*
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
*/

int main()
{
  /*
    Create two linked lists

    1st 3->6->9->15->30
    2nd 10->15->30

    15 is the intersection point
  */

  struct node* newNode;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;

  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;

  head1->next->next->next = NULL;

  cout << "The intersection point of the two linked list is: ";
  struct node* intersectionPoint = getIntersectionNode(head1, head2);
  cout << intersectionPoint -> data << endl;

  return 0;
}
