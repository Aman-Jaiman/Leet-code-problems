#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        if (strs.empty()) return ans; // edge case

        // Outer loop: go through each character of first word
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i]; // ith character of first string

            // Compare with all other strings
            for (int j = 1; j < strs.size(); j++) {
                // check: string khatam ho gayi ya mismatch
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return ans; // mismatch -> return current prefix
                }
            }

            // agar sabhi me match mila to ans me add karo
            ans += ch;
        }

        return ans;
    }
};

// Driver code for testing
int main() {
    Solution sol;
    vector<string> strs1 = {"flower","flow","flight"};
    vector<string> strs2 = {"dog","racecar","car"};

    cout << "Example 1: " << sol.longestCommonPrefix(strs1) << endl; // Output: fl
    cout << "Example 2: " << sol.longestCommonPrefix(strs2) << endl; // Output: (empty string)

    return 0;
}
