// Program to find the majority element
// in the array
// http://www.geeksforgeeks.org/check-for-majority-element-in-a-sorted-array/

#include <iostream>

using namespace std;

bool is_majority (int* array, int n, int x)
{
    for (int i = 0; i <= n / 2; i++) {
        if (array[i] == x and array[n / 2 + i] == x) {
            return true;
        }
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int x;

    int array[n];
    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << "Enter the element to be checked for: " << endl;
    cin >> x;

    bool majority = is_majority (array, n, x);
    
    if (majority) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
