#include <bits/stdc++.h>
using namespace std;

// ====================
// Space Optimized O(n)
// ====================
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<long long> dp(n, 0);

        dp[0] = (obstacleGrid[0][0] == 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                }
                else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        if (obstacleGrid[0][0] == 1) return 0;

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                if (i == 0 && j == 0) continue;

                long long up = 0, left = 0;

                if (i > 0) up = dp[i - 1][j];
                if (j > 0) left = dp[i][j - 1];

                dp[i][j] = up + left;
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
    int helper(int i, int j,
               vector<vector<int>>& obstacleGrid,
               vector<vector<int>>& dp) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (i >= m || j >= n) return 0;

        if (obstacleGrid[i][j] == 1) return 0;

        if (i == m - 1 && j == n - 1) return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = helper(i + 1, j, obstacleGrid, dp);
        int right = helper(i, j + 1, obstacleGrid, dp);

        return dp[i][j] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(0, 0, obstacleGrid, dp);
    }
};