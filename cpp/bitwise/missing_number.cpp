// Program to find missing number
// Same program is done in arrays folder
// by a different approach
// Input is a sequence containing n - 1
// elements, where the all the elements
// are in range 1 to n. No element occurs
// multiple times.
// Output is the missing element.

#include <iostream>

using namespace std;

// No idea how this is working
int get_missing_element(int* array, int n)
{
    int xor_1;
    int xor_2;

    xor_1 = 0;
    for (int i = 0; i < n - 1; i++) {
        xor_1 = xor_1 ^ array[i];
    }

    xor_2 = 0;
    for (int i = 1; i <= n; i++) {
        xor_2 = xor_2 ^ i;
    }

    int missing = xor_1 ^ xor_2;
    return missing;
}

int main()
{
    int n;
    cout << "Enter the actual sequence length (with the missing element: ";
    cout << endl;
    cin >> n;

    int array[n - 1];
    cout << "Enter the sequence: " << endl;
    for (int i = 0; i < n - 1; i++) {
        cin >> array[i];
    }

    int missing = get_missing_element(array, n);
    
    cout << "The missing element is: " << missing << endl;
    return 0;
}
