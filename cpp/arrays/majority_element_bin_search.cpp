// Same problem as in majority_element_linear
// http://www.geeksforgeeks.org/check-for-majority-element-in-a-sorted-array/

#include <iostream>

using namespace std;

// This function will return the
// first index of the element if
// it is found or -1 if the element
// is not found at all.
int _bin_search (int* array, int low, int high, int x)
{
    if (low <= high) {
        int mid = (low + high) / 2;

        // This block is different from what
        // i would usually write for a bin search
        // The ordering of the if else for x < a[mid]
        // and x > a[mid] is important if this program
        // has to function.
        // Since, we want the first appearance of the
        // element to be found in this function, we
        // would like that if we find that some
        // element is equal to x, but is not
        // the first element then we want to search
        // the left half of the subarray rather than
        // the right half. To ensure this, searching
        // in the left half should be made the default
        // case or rather it should be under else
        // statement.
        if ((mid == 0 || array[mid - 1] < x) && (array[mid] == x)) {
            return mid;
        } else if (x > array[mid]) {
            return _bin_search (array, mid + 1, high, x);
        } else {
            return _bin_search (array, low, mid - 1, x);
        }

    }

    // If the element if not found
    return -1;
}

bool is_majority (int* array, int n, int x)
{
    int index = _bin_search (array, 0, n - 1, x);

    if (index == -1) {
        cout << "From here" << endl;
        return false;
    }

    if ((index + n / 2 < n) && array[index + n / 2] == x) {
            return true;
    }

    return false;
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

    cout << "Enter the number to be checked for: " << endl;
    int x;
    cin >> x;

    bool majority = is_majority (array, n, x);

    if (majority) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
