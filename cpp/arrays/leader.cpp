// Write a program to print all the LEADERS in the array.
// An element is leader if it is greater than all the
// elements to its right side. And the rightmost element is
// always a leader.

#include <iostream>

using namespace std;

// The idea is that if you traverse
// from the right, then except for the
// first element which by default is
// a leader, one becomes a leader
// if it is larger than the last
// leader
void leaders(int* array, int n)
{
    int i;
    int leader_index; // Keeps track of the leader element

    cout << "The leader element(s) of the array are: " << endl;
    i = n - 1;
    while(i) {
        if (i == n - 1) {
            leader_index = i;
            cout << array[leader_index] << " ";
        } else {
            if (array[i] > array[leader_index]) {
                leader_index = i;
                cout << array[leader_index] << " ";
            }
        }

        i--;
    }

    cout << endl;
    return;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    int array[n];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    leaders(array, n);

    return 0;
}
