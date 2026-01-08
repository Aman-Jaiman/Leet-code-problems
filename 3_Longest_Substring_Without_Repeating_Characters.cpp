/*
Problem: Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring
without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.

LeetCode Problem: 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int start = 0;
        int ans = 0;

        for (int end = 0; end < s.length(); end++) {
            freq[s[end]]++;

            // Shrink window until no duplicate
            while (freq[s[end]] > 1) {
                freq[s[start]]--;
                start++;
            }

            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";

    cout << "Input: " << s1 << " -> Output: "
         << sol.lengthOfLongestSubstring(s1) << endl;

    cout << "Input: " << s2 << " -> Output: "
         << sol.lengthOfLongestSubstring(s2) << endl;

    cout << "Input: " << s3 << " -> Output: "
         << sol.lengthOfLongestSubstring(s3) << endl;

    return 0;
}
