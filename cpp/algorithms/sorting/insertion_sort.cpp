// Insertion sort to sort integers in cpp

#include <iostream>

using namespace std;

void insertion_sort(int* array, int n)
{
    int i;
    int j;
    int key;

    for (j = 1; j < n; j++) {
        key = array[j];
        for (i = j - 1; i >= 0 && key < array[i]; i--) {
            array[i + 1] = array[i];
        }

        // i + 1 because - when loop ends it has decreased it's index
        // where the actual shifting was done
        array[i + 1] = key;
    }

    return;
}

int main()
{
    int n;
    cout << "Enter the size of array: " << endl;
    cin >> n;

    int array[n];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // Sort the array
    insertion_sort(array, n);

    // Print the array
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}
