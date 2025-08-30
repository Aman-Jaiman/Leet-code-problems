/*
LeetCode Problem 9: Palindrome Number

Given an integer x, return true if x is palindrome integer.

Example 1:
Input: x = 121
Output: true

Example 2:
Input: x = -121
Output: false

Example 3:
Input: x = 10
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
       if (x < 0)
      return false;   // negative numbers are not palindrome

    long reversed = 0;    // use long to avoid overflow while reversing
    int y = x;    // keep original number safe

    while (y > 0) {
      reversed = reversed * 10 + y % 10;
      y /= 10;
    }

    return reversed == x;   // compare reversed with original
    }
};

// 🔹 Driver code
int main() {
    Solution obj;

    int num = 121;
    cout << num << " is palindrome? " 
         << (obj.isPalindrome(num) ? "true" : "false") << endl;

    num = -121;
    cout << num << " is palindrome? " 
         << (obj.isPalindrome(num) ? "true" : "false") << endl;

    num = 10;
    cout << num << " is palindrome? " 
         << (obj.isPalindrome(num) ? "true" : "false") << endl;

    return 0;
}
