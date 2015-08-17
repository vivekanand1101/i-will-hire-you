// Program to find the minimum distance
// between any given two elements which
// are known to be present in the array

#include <iostream>

using namespace std;

int min_dist_btw_elements(int* array, int n)
{
    sort(array, array + n);

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

    int min_dist = min_dist_btw_elemements(array, n);

    cout << "The required minimum distance is: " << endl;
    cout << min_dist;

    return 0;
}
