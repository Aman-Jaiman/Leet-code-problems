/*
Problem: Palindrome Partitioning (LeetCode 131)

Given a string s, partition s such that every substring
of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Example:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check palindrome
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    // Backtracking function
    void getAllParts(string s, vector<string>& partition,
                     vector<vector<string>>& ans) {
        // Base case
        if (s.size() == 0) {
            ans.push_back(partition);
            return;
        }

        // Try all prefixes
        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);

            if (isPalindrome(part)) {
                partition.push_back(part);
                getAllParts(s.substr(i + 1), partition, ans);
                partition.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        getAllParts(s, partition, ans);
        return ans;
    }
};



int main() {
    Solution obj;
    string s = "aab";
    vector<vector<string>> result = obj.partition(s);

    for (auto v : result) {
        for (auto str : v)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}

