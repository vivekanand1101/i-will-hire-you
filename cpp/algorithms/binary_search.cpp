// Program to search for a number 'n' using binary search in a sorted array

#include <iostream>
#include <cstdlib>

using namespace std;


bool binsearch (int* a, int low, int high, int n)
{
    int mid;
    mid = (int)((low + high) / 2);

    // Checking for base case
    if (low >= high) {
        return false;
    }

    if (n == a[mid]) {
        return true;
    } else if (n < a[mid]) {
        return binsearch(a, low, mid, n);
    } else if (n > a[mid]) {
        return binsearch(a, mid + 1, high, n);
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int n;
    int array[size];

    cout << "Now, enter the numbers in the array" << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i];
        if (i > 0 && (array[i] <= array[i - 1])) {
            cout << "Please enter the numbers in sorted order" << endl;
            exit(1);
        }
    }

    cout << "Enter the number to be searched" << endl;
    cin >> n;
    if (binsearch(array, 0, size, n)) {
        cout << "The number was present in the array" << endl;
    } else {
        cout << "No, Not present in the array" << endl;
    }

    return 0;
}
