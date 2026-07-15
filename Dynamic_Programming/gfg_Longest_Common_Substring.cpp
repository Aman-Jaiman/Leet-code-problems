#include <bits/stdc++.h>
using namespace std;

// Memoization
class SolutionMemoization {
public:
    int ans = 0;

    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        f(i - 1, j, s1, s2, dp);
        f(i, j - 1, s1, s2, dp);

        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
            ans = max(ans, dp[i][j]);
        } else {
            dp[i][j] = 0;
        }

        return dp[i][j];
    }

    int longCommSubstr(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        f(n - 1, m - 1, s1, s2, dp);

        return ans;
    }
};

// Tabulation
class SolutionTabulation {
public:
    int longCommSubstr(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }
};

// Space Optimization
class SolutionSpaceOptimized {
public:
    int longCommSubstr(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    ans = max(ans, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }

            prev = curr;
            fill(curr.begin(), curr.end(), 0);
        }

        return ans;
    }
};