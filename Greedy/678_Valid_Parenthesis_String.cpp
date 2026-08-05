#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    bool helper(string &s, int i, int count) {
        if (count < 0) return false;

        if (i == s.size())
            return count == 0;

        if (dp[i][count] != -1)
            return dp[i][count];

        bool ans;

        if (s[i] == '(') {
            ans = helper(s, i + 1, count + 1);
        }
        else if (s[i] == ')') {
            ans = helper(s, i + 1, count - 1);
        }
        else {
            ans = helper(s, i + 1, count) ||
                  helper(s, i + 1, count + 1) ||
                  helper(s, i + 1, count - 1);
        }

        return dp[i][count] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));

        return helper(s, 0, 0);
    }
};