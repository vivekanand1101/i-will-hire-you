// Program to find the indices and value of
// the two elements whose sum is closest to zero

#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

void min_sum(int* array, int n)
{
    sort(array, array + n);

    // The two pointers  pointing to beginning and end
    int l;
    int r;

    // The two pointers which will keep track of the
    // indices which produce the minimum value close
    // to zero
    int min_l;
    int min_r;

    // To store the sum of the values pointed
    // by the two pointers
    int sum;

    // Initializing the pointers to the beginning
    // and end
    l = 0;
    r = n - 1;

    // Keep track of the min sum closest to zero
    int min = INT_MAX;

    while (l < r) {
        sum = array[l] + array[r];

        // Check for min sum close to zero
        // and if needed update the min
        // value and pointers which caused
        // those min value
        if (abs(sum) < abs(min)) {
            min = sum;
            min_l = l;
            min_r = r;
        }


        // The idea is that if the sum
        // is greater than zero then
        // we should ensure that in next
        // iteration, we reach closer to zero
        // i.e, decrease the right pointer's
        // value. The same stands when the
        // value has to be increased in case the
        // sum is less than zero. Overall idea,
        // just bring the sum close to zero.
        if (sum > 0) {
            r--;
        } else {
            l++;
        }

    }

    cout << "The min sum closest to zero is: " << min << endl;
    cout << "The indices which cause the min sum: ";
    cout << min_l << " " << min_r << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    int array[n];
    int sum;

    cout << "Enter the elements: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    min_sum(array, n);

    return 0;
}
