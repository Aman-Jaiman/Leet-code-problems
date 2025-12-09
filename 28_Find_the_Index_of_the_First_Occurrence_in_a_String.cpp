// File: 28. Find the Index of the First Occurrence in a String.cpp
//
// Problem: 28. Find the Index of the First Occurrence in a String
//
// Given two strings needle and haystack, return the index of the first occurrence
// of needle in haystack, or -1 if needle is not part of haystack.
//
// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6. The first occurrence is at index 0.
//
// Example 2:
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode".
//
// Constraints:
// - 1 <= haystack.length, needle.length <= 10^4
// - haystack and needle consist of only lowercase English characters.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();

        // Edge case: if needle is bigger than haystack, it can never occur
        if (n > m) return -1;

        for (int i = 0; i <= m - n; i++) {
            if (haystack.substr(i, n) == needle)
                return i;
        }
        return -1;
    }
};

// ---------- Helper main for local testing (not needed on LeetCode) ----------

int main() {
    string haystack, needle;

    cout << "Enter haystack string: ";
    cin >> haystack;

    cout << "Enter needle string: ";
    cin >> needle;

    Solution sol;
    int index = sol.strStr(haystack, needle);

    cout << "First occurrence index: " << index << endl;

    return 0;
}
