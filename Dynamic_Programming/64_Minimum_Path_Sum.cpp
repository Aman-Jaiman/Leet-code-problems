#include <bits/stdc++.h>
using namespace std;

// ====================
// Space Optimized O(n)
// ====================
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);

            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) {
                    curr[j] = grid[i][j];
                }
                else {
                    int up = INT_MAX;
                    int left = INT_MAX;

                    if (i > 0)
                        up = grid[i][j] + prev[j];

                    if (j > 0)
                        left = grid[i][j] + curr[j - 1];

                    curr[j] = min(up, left);
                }
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};


// ====================
// Tabulation O(m*n)
// ====================
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                }
                else {
                    int up = INT_MAX;
                    int left = INT_MAX;

                    if (i > 0)
                        up = grid[i][j] + dp[i - 1][j];

                    if (j > 0)
                        left = grid[i][j] + dp[i][j - 1];

                    dp[i][j] = min(up, left);
                }
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
               vector<vector<int>>& grid,
               vector<vector<int>>& dp) {

        if (i >= grid.size() || j >= grid[0].size())
            return INT_MAX;

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = helper(i + 1, j, grid, dp);
        int right = helper(i, j + 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(0, 0, grid, dp);
    }
};