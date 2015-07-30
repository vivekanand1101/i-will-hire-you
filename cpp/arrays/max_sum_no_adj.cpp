// Given an array of positive numbers, find the maximum sum of a subsequence
// with the constraint that no 2 numbers in the sequence should be adjacent in
// the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7
// should return 15 (sum of 3, 5 and 7).Answer the question in most efficient
// way.

#include <iostream>

using namespace std;

// Dynamic programming question
// Using bottom up algorithm
int max_sum_no_adj(int* array, int n)
{
    int i;
    int b[n];

    i = 0;
    while(i != n) {

        // If it is the first element
        // then max sum would be
        // the element itself.
        // If it is the second element,
        // the max sum would be either
        // the first element or the second
        // element (the greater of the two).
        // (since, no adjacent element is
        // allowed)
        // But, if these are not the cases, then
        // the max sum would be the the sum
        // of the current element with the
        // sum till the (i - 2)th element or
        // the sum till the (i - 1)th element
        // only.
        if (i == 0) {
            b[i] = array[i];
        } else if (i == 1) {
            b[i] = max(array[i], array[i - 1]);
        } else {
            b[i] = max(array[i] + b[i - 2], b[i - 1]);
        }

        i++;
    }

    return max(b[i], b[i - 1]);
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

    int max_sum = max_sum_no_adj(array, n);

    cout << "The required sum is: " << max_sum << endl;

    return 0;
}
