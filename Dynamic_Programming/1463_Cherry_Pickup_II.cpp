#include <bits/stdc++.h>
using namespace std;

// ====================
// Space Optimized O(n²)
// ====================
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prev(n, vector<int>(n, 0));

        // Base case
        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {
                if (j1 == j2)
                    prev[j1][j2] = grid[m - 1][j1];
                else
                    prev[j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }

        for (int i = m - 2; i >= 0; i--) {

            vector<vector<int>> curr(n, vector<int>(n, 0));

            for (int j1 = 0; j1 < n; j1++) {

                for (int j2 = 0; j2 < n; j2++) {

                    int maxi = -1e9;

                    for (int d1 = -1; d1 <= 1; d1++) {

                        for (int d2 = -1; d2 <= 1; d2++) {

                            int value;

                            if (j1 + d1 >= 0 && j1 + d1 < n &&
                                j2 + d2 >= 0 && j2 + d2 < n)
                                value = prev[j1 + d1][j2 + d2];
                            else
                                value = -1e9;

                            if (j1 == j2)
                                value += grid[i][j1];
                            else
                                value += grid[i][j1] + grid[i][j2];

                            maxi = max(maxi, value);
                        }
                    }

                    curr[j1][j2] = maxi;
                }
            }

            prev = curr;
        }

        return prev[0][n - 1];
    }
};


// ====================
// Tabulation O(m*n²)
// ====================
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(n, 0))
        );

        // Base case
        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {
                if (j1 == j2)
                    dp[m - 1][j1][j2] = grid[m - 1][j1];
                else
                    dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }

        for (int i = m - 2; i >= 0; i--) {

            for (int j1 = 0; j1 < n; j1++) {

                for (int j2 = 0; j2 < n; j2++) {

                    int maxi = -1e9;

                    for (int d1 = -1; d1 <= 1; d1++) {

                        for (int d2 = -1; d2 <= 1; d2++) {

                            int value;

                            if (j1 + d1 >= 0 && j1 + d1 < n &&
                                j2 + d2 >= 0 && j2 + d2 < n)
                                value = dp[i + 1][j1 + d1][j2 + d2];
                            else
                                value = -1e9;

                            if (j1 == j2)
                                value += grid[i][j1];
                            else
                                value += grid[i][j1] + grid[i][j2];

                            maxi = max(maxi, value);
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][n - 1];
    }
};


// ====================
// Memoization
// ====================
class Solution {
public:
    int helper(int i, int j1, int j2,
               int m, int n,
               vector<vector<int>>& grid,
               vector<vector<vector<int>>>& dp) {

        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
            return -1e9;

        if (i == m - 1) {
            if (j1 == j2)
                return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = -1e9;

        for (int d1 = -1; d1 <= 1; d1++) {

            for (int d2 = -1; d2 <= 1; d2++) {

                int value = helper(i + 1,
                                   j1 + d1,
                                   j2 + d2,
                                   m, n,
                                   grid, dp);

                if (j1 == j2)
                    value += grid[i][j1];
                else
                    value += grid[i][j1] + grid[i][j2];

                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(n, -1))
        );

        return helper(0, 0, n - 1, m, n, grid, dp);
    }
};