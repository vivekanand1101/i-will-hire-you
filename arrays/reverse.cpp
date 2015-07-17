// Program to reverse an array iteratively

#include <iostream>
#include <cstdlib>

using namespace std;

void reverse(int* array, int n)
{
    int i;
    int j;
    int temp;

    i = 0;
    j = n - 1;

    while (i < j) {
        swap(array[i++], array[j--]);
    }

    return;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    int array[n];

    cout << "Enter the numbers: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    reverse(array, n);

    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}
