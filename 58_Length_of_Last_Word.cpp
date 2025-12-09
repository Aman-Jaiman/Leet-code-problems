// File: 58. Length of Last Word.cpp
//
// Problem: 58. Length of Last Word
//
// Given a string s consisting of uppercase and lowercase letters and spaces,
// return the length of the last word in the string.
//
// A word is a sequence of non-space characters.
//
// Examples:
// Input: s = "Hello World"
// Output: 5
//
// Input: s = "   fly me   to   the moon  "
// Output: 4
//
// Input: s = "luffy is still joyboy"
// Output: 6
//
// Constraints:
// - 1 <= s.length <= 10^4
// - s contains only English letters and spaces ' '
// - There will be at least one word in s

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count the characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

// ----------------- Local Testing (not required for LeetCode) -----------------

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    Solution sol;
    int result = sol.lengthOfLastWord(s);

    cout << "Length of last word: " << result << endl;
    return 0;
}
