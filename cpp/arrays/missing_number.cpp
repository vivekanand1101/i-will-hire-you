// Program to find the missing number
// in a sequence of numbers

// You are given a list of n-1 integers and these
// integers are in the range of 1 to n
// There are no duplicates in list
// One of the integers is missing in the list

#include <iostream>

using namespace std;

// The idea is, if the range is given
// and no element is repeating and only
// one element is missing. Then we know
// the sum of those elements if no element
// was absent. Just subtract each element
// which is present, you will be left
// with the element which is missing.
int get_missing_number(int* array, int n)
{
    int sum;
    sum = (n * (n + 1)) / 2;

    for (int i = 0; i < n - 1; i++) {
        sum = sum - array[i];
    }

    return sum;
}

int main()
{
    int n;
    cout << "Enter the length of actual sequence";
    cout << " (with the missing number present): " << endl;
    cin >> n;

    int array[n - 1];
    cout << "Enter the elements: " << endl;

    for (int i = 0; i < n - 1; i++) {
        cin >> array[i];
    }

    int missing = get_missing_number(array, n);

    cout << "The missing number is: " << missing << endl;
    return 0;
}
