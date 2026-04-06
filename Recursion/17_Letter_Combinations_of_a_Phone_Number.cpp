#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ans;

    void backtrack(string &digits, int i, string &curr, vector<string> &mp) {
        if (i == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[i] - '0'];

        for (char c : letters) {
            curr.push_back(c);
            backtrack(digits, i + 1, curr, mp);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string curr = "";
        backtrack(digits, 0, curr, mp);

        return ans;
    }
};