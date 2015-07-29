// Program to find a number which
// is occuring odd number of times
// in a sequence of n numbers in
// which all other numbers occur
// even number of times. The output
// is the number itself.

#include <iostream>
#include <cstdlib>

using namespace std;

// The function which gets the
// element which occurs odd number
// of times. The idea is that
// if you "xor" a, b and c
// in any sequence, then the
// result is same. Now, if you
// "xor" a with 0 then the result
// is a and a "xor" a is 0
// Taking into consideration
// all the three points above
// here 'e' is the element which
// occurs odd number of times
// Also, there should be
// no other element which occurs odd
// number of times
int get_element_occurring_odd_times(int* array, int n)
{
    int e = 0;
    for (int i = 0; i < n; i++) {
        e = e ^ array[i];
    }

    return e;
}

int main()
{
    int n;
    cout << "Enter the length of sequence: " << endl;
    cin >> n;

    int array[n];

    cout << "Enter the numbers: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int odd_times = get_element_occurring_odd_times(array, n);
    cout << "The element occurring odd number of times is: ";
    cout << odd_times << endl;

    return 0;
}
