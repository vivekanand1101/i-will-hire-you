// Given an array A[] and a number x
// check for pair in A[] with sum as x

#include <iostream>
#include <algorithm> // for the sort function

using namespace std;

// The idea is to sort the array first
// Once sorted in non-decreasing order,
// if we move a pointer from left to right,
// the value the pointer points to increases
// while if right to left it decreases. The same
// idea is applied here. We take two pointers
// which point to different indices of the array
// and we move one of them on the basis that
// whether the sum of the two elements pointed by
// the pointer is less or more than the value of x.
bool sum_of_pair_of_elements(int* array, int n, int x)
{
    sort(array, array + n);

    // The two pointers
    int i = 0;
    int j = n - 1;

    while(i < j) {
        if (array[i] + array[j] == x) {
            return true;
        } else if (array[i] + array[j] < x) {
            i++;
        } else if (array[i] + array[j] > x) {
            j++;
        }
    }

    // We couldn't find any two elements
    return false;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int array[n];
    int x;
    int data;

    cout << "Enter the numbers to be inserted: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << "Enter the number to be checked for the sum: " << endl;
    cin >> x;

    bool flag = sum_of_pair_of_elements(array, n, x);

    if (flag) {
        cout << "Exists" << endl;
    } else {
        cout << "Does not exists" << endl;
    }

    return 0;
}
