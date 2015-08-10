// Program to find the maximum diff
// between two elements with the constraint
// that the larger element is on the right
// to the smaller element

#include <iostream>

using namespace std;

// The idea is to traverse and keep track of
// two things:
// 1. Max difference till now
// 2. Min element till now
// So, you take an element and check it
// with the min element so far for the
// max difference. Maintain the same
// throughout the array, and the max diff
// will be the answer you need.
int max_diff_two_elements(int* array, int n)
{
    int max_diff = 0;
    int min_element = array[0];

    for (int i = 0; i < n; i++) {

        // Maintaining the max difference
        if (array[i] - min_element > max_diff) {
            max_diff = array[i] - min_element;
        }
        
        // Maintaining the min element
        if (array[i] < min_element) {
            min_element = array[i];
        }
    }

    return max_diff;
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

    int max_diff = max_diff_two_elements(array, n);
    cout << "The req max diff between two elements: " << max_diff << endl;

    return 0;
}
