#include <bits/stdc++.h>
using namespace std;

// Space Optimized
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<double> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            curr[0] = 1;

            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    curr[j] = prev[j - 1] + prev[j];
                else
                    curr[j] = prev[j];
            }

            prev = curr;
        }

        return (int)prev[m];
    }
};



// Tabulation
class Solution_Tabulation {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return (int)dp[n][m];
    }
};



// Memoization
class Solution_Memoization {
public:
    double helper(int i, int j, string &s, string &t,
                  vector<vector<double>> &dp) {

        if (j < 0)
            return 1;

        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] =
                helper(i - 1, j - 1, s, t, dp) +
                helper(i - 1, j, s, t, dp);
        }

        return dp[i][j] = helper(i - 1, j, s, t, dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<double>> dp(n, vector<double>(m, -1));

        return (int)helper(n - 1, m - 1, s, t, dp);
    }
};