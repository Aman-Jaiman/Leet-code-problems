#include <bits/stdc++.h>
using namespace std;

// Memoization
class SolutionMemoization {
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) return true;
        if (j < 0) return false;

        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (p[j] == '*')
            return dp[i][j] = f(i, j - 1, s, p, dp) || f(i - 1, j, s, p, dp);

        if (p[j] == '?' || s[i] == p[j])
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n - 1, m - 1, s, p, dp);
    }
};

// Tabulation
class SolutionTabulation {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++) {
            bool flag = true;
            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};

// Space Optimization
class SolutionSpaceOptimized {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<bool> prev(m + 1, false), curr(m + 1, false);

        prev[0] = true;

        for (int j = 1; j <= m; j++) {
            bool flag = true;
            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for (int i = 1; i <= n; i++) {
            curr[0] = false;

            for (int j = 1; j <= m; j++) {

                if (p[j - 1] == '*') {
                    curr[j] = curr[j - 1] || prev[j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    curr[j] = prev[j - 1];
                }
                else {
                    curr[j] = false;
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};