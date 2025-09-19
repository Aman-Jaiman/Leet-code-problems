/*
LeetCode 567. Permutation in String
------------------------------------------------------
Question:
Given two strings s1 and s2, return true if s2 contains 
a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations 
is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:
- 1 <= s1.length, s2.length <= 10^4
- s1 and s2 consist of lowercase English letters.
------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to compare two frequency arrays
    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {}; // frequency of characters in s1
        int windowSize = s1.length();

        // build frequency array for s1
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        // check every possible substring of s2 of length windowSize
        for (int i = 0; i <= s2.length() - windowSize; i++) {
            int windowFreq[26] = {};
            int windowIdx = 0, idx = i;

            // build frequency array for current window of s2
            while (windowIdx < windowSize && idx < s2.length()) {
                windowFreq[s2[idx] - 'a']++;
                windowIdx++;
                idx++;
            }

            // compare with s1 frequency
            if (isFreqSame(freq, windowFreq)) {
                return true; // found permutation
            }
        }

        return false; // no permutation found
    }
};

int main() {
    Solution sol;
    cout << (sol.checkInclusion("ab", "eidbaooo") ? "true" : "false") << endl; // true
    cout << (sol.checkInclusion("ab", "eidboaoo") ? "true" : "false") << endl; // false
    return 0;
}
