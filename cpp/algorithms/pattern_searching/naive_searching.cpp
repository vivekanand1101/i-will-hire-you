// Naive algorithm for searching a pattern in some text

#include <iostream>

// for using 'strlen'
#include <cstring>

using namespace std;

void* pattern_search(char* text, char* pattern)
{
    int len_text = strlen(text);
    int len_pattern = strlen(pattern);

    // Indices of the two loops
    int i;
    int j;

    // Holding the index of text
    // when the pattern is being checked
    int k;

    // If the characters match,
    // it would be marked as '1'
    // ,'0' otherwise. If all
    // the all the characters of pattern
    // matches, then we have found the
    // pattern.
    int flag;

    // The outer loop runs till the length of the
    // text after which the pattern cannot exist
    // (The pattern cannot be of lesser size than
    // itself)
    for (i = 0; i < len_text - len_pattern + 1; i++) {

        // This allows 'i' to rest at
        // the index from where the pattern
        // was started to be searched
        k = i;

        // If characters match, then
        // flag is '1', else '0'
        flag = 0;

        // For a particular 'i', check if
        // all the characters start matching
        // from that 'i' in text with those
        // characters in pattern
        for (j = 0; j < len_pattern; j++) {
            if (text[k] != pattern[j]) {
                flag = 0;
                break;
            }

            k++;
            flag = 1;
        }

        // Remember, it outputs the position, not index
        if (flag == 1) {
            cout << "Pattern found at position: " << k << endl;
        }
    }
}

int main()
{
    char text[1000];
    char pattern[20];

    cout << "Enter the text: " << endl;
    cin.getline(text, 1000);
    cout << "Enter the pattern: " << endl;
    cin.getline(pattern, 20);

    pattern_search(text, pattern);

    return 0;
}
