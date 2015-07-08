// Basic operations on Queue
// Here Queue is implemented using arrays



#include <iostream>
#include <cstdlib>

using namespace std;

// The structure which represents the queue
struct Queue {
    int size; // size of the queue
    int front; // Index to store the front element in the queue
    int rear; // Index to store the last element in the queue
    unsigned capacity; // The capacity of the queue
    int* data; // The array to store the values
};

void options()
{
    cout << "Enter these characters for the corresponding operations: " << endl;
    cout << "   1. 'e' for 'enqueue' " << endl;
    cout << "   2. 'd' for 'dequeue' " << endl;
    cout << "   3. 'f' for 'front' " << endl;
    cout << "   4. 'r' for 'rear' " << endl;
    cout << "   5. 'q' for 'quit' " << endl;
    cout << "   6. 'o' for 'repeat these options' " << endl;

    return;
}

bool isEmpty(struct Queue* queue)
{
    if (queue -> size == 0) {
        return true;
    } else {
        return false;
    }
}

bool isFull(struct Queue* queue)
{
    if (queue -> size == queue -> capacity) {
        return true;
    } else {
        return false;
    }
}

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));

    // Allocates memory to the structure representing the queue
    queue -> capacity = capacity;

    // Allocates memory for storing elements of the queue
    queue -> data = (int*) malloc((queue -> capacity) * sizeof(int));

    // This variable stores the index of the element which is in the line to be
    // dequeued. This increase when an element is dequeued from the queue
    queue -> front = 0;

    // Can also initialize to -1 without any change in code, since using '%' in enqueue
    // Reminder: This rear is the variable 'rear' for the structure. It stores
    // just the index of rear element. It increases as the queue is enqueued.
    queue -> rear = capacity - 1;

    return queue;
}

// Enqueues an element only when the queue is not full
void enqueue(struct Queue* queue, int data)
{
    if (isFull(queue)) {
        cout << "Queue is full - no more enqueue before any dequeue" << endl;
        return;
    }

    queue -> size = queue -> size + 1;
    queue -> rear = (queue -> rear + 1) % queue -> capacity;

    cout << "Enqueued: " << data << endl;
    queue -> data[queue -> rear] = data;
    return;
}

// Dequeues an element, the empty case is checked in the main function
int dequeue(struct Queue* queue)
{
    int item;
    queue -> size = queue -> size - 1;
    item = queue -> data[queue -> front];
    queue -> front = (queue -> front + 1) % queue -> capacity;

    return item;
}

// The function which return which 'data' is in the 'front' variable
int front(struct Queue* queue)
{
    return queue -> data[queue -> front];
}

// The function which returns which 'data' is in the 'rear' variable
int rear(struct Queue* queue)
{
    return queue -> data[queue -> rear];
}

int main()
{
    struct Queue* queue = createQueue(100);
    int data;
    char input;
    int n;

    options();
    cin >> input;
    while (input != 'q') {
        if (input == 'e') {
            cout << "Enter the number of elements you want to enqueue: " << endl;
            cin >> n;
            cout << "Now, enter the numbers you want to enqueue: " << endl;
            for (int i = 0; i < n; i++) {
                cin >> data;
                enqueue(queue, data);
            }
        } else if (input == 'd') {
            if (isEmpty(queue)) {
                cout << "Queue is empty - no dequeues before any enqueue" << endl;
            } else {
                cout << "Dequeued item: " << dequeue(queue) << endl;
            }
        } else if (input == 'f') {
            if (isEmpty(queue)) {
                cout << "The queue is empty" << endl;
            } else {
                cout << "The front item is: " << front(queue) << endl;
            }
        } else if (input == 'r') {
            if (isEmpty(queue)) {
                cout << "The queue is empty" << endl;
            } else {
                cout << "The rear item is: " << rear(queue) << endl;
            }
        } else if (input == 'o') {
            options();
        }

        cin >> input;
    }

    return 0;
}
