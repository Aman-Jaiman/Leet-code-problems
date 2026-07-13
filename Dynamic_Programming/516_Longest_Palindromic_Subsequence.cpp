#include <bits/stdc++.h>
using namespace std;


// Approach 1 : Space Optimized
// Time  : O(n^2)
// Space : O(n)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<int> next(n, 0), curr(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            curr[i] = 1;

            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    curr[j] = 2 + next[j - 1];
                else
                    curr[j] = max(next[j], curr[j - 1]);
            }

            next = curr;
        }

        return next[n - 1];
    }
};


// Approach 2 : Tabulation
// Time  : O(n^2)
// Space : O(n^2)


class Solution2 {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};


// Approach 3 : Memoization
// Time  : O(n^2)
// Space : O(n^2) + O(n)


class Solution3 {
public:
    int f(int i, int j, string &s, vector<vector<int>> &dp) {
        if (i > j)
            return 0;

        if (i == j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = 2 + f(i + 1, j - 1, s, dp);

        return dp[i][j] = max(f(i + 1, j, s, dp),
                              f(i, j - 1, s, dp));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, n - 1, s, dp);
    }
};