#include <bits/stdc++.h>
using namespace std;

// ====================
// Space Optimized O(n)
// ====================
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};


// ====================
// Tabulation O(m*n)
// ====================
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


// ====================
// Memoization
// ====================
class Solution {
public:
    int helper(int i, int j, int m, int n,
               vector<vector<int>>& dp) {

        if (i >= m || j >= n) return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = helper(i + 1, j, m, n, dp);
        int right = helper(i, j + 1, m, n, dp);

        return dp[i][j] = down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(0, 0, m, n, dp);
    }
};