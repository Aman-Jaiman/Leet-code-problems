/*
LeetCode 1910. Remove All Occurrences of a Substring
------------------------------------------------------
Question:
Given two strings s and part, perform the following operation on s 
until all occurrences of the substring part are removed:

- Find the leftmost occurrence of the substring part and remove it from s.

Return s after removing all occurrences of part.

Example 1:
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: 
- Remove "abc" at index 2 → "dabaabcbc"
- Remove "abc" at index 4 → "dabcbc"
- Remove "abc" at index 3 → "dab"

Example 2:
Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"

Constraints:
- 1 <= s.length <= 1000
- 1 <= part.length <= 1000
- s and part consist of lowercase English letters.
------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()>0 && s.find(part)<s.length()){
            s.erase(s.find(part),part.length());
        }
       return s; 
    }
};

int main() {
    Solution sol;
    
    string s1 = "daabcbaabcbc";
    string part1 = "abc";
    cout << "Input: " << s1 << ", part = " << part1 
         << "\nOutput: " << sol.removeOccurrences(s1, part1) << endl;

    string s2 = "axxxxyyyyb";
    string part2 = "xy";
    cout << "Input: " << s2 << ", part = " << part2 
         << "\nOutput: " << sol.removeOccurrences(s2, part2) << endl;

    return 0;
}
