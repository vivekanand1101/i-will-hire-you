// Inversion Count for an array indicates – how far (or close)
// the array is from being sorted. If array is already sorted
// then inversion count is 0. If array is sorted in reverse
// order that inversion count is the maximum. Formally speaking,
// two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

#include <iostream>
#include <climits>

using namespace std;

int merge_inversions(int* array, int low, int mid, int high)
{
    int n1;
    int n2;
    int count;
    int i;
    int j;

    n1 = mid - low + 1;
    n2 = high - mid;

    int left[n1 + 1];
    int right[n2 + 1];

    left[n1] = INT_MAX;
    right[n2] = INT_MAX;

    for (int i = 0; i < n1; i++) {
        left[i] = array[i];
    }

    for (int i = 0; i < n2; i++) {
        right[i] = array[i + mid + 1];
    }

    i = 0;
    j = mid + 1;
    count = 0;
    int k = 0;
    while (k != high) {
        if (left[i++] > right[j++]) {
            count++;
            cout << "Count: " << count << endl;
        }

        k++;
    }

    return count;
}

int count_inversions(int* array, int low, int high)
{
    int left;
    int right;
    static int total = 0;
    int mid;

    if (low < high) {
        mid = (low + high) / 2;
        left = count_inversions(array, low, mid);
        right = count_inversions(array, mid + 1, high);
        total = merge_inversions(array, low, mid, high) + left + right;
    }

    return total;
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

    int inversions = count_inversions(array, 0, n - 1);

    cout << "Number of inversions in the array are: " << inversions << endl;

    return 0;
}
