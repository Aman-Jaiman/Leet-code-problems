#include <bits/stdc++.h>
using namespace std;

// ====================
// Space Optimized O(n)
// ====================
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<int> prev = triangle[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n, 0);

            for (int j = 0; j <= i; j++) {
                curr[j] = triangle[i][j] +
                          min(prev[j], prev[j + 1]);
            }

            prev = curr;
        }

        return prev[0];
    }
};


// ====================
// Tabulation O(n²)
// ====================
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case
        for (int j = 0; j < n; j++)
            dp[n - 1][j] = triangle[n - 1][j];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j] +
                           min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        return dp[0][0];
    }
};


// ====================
// Memoization
// ====================
class Solution {
public:
    int helper(int i, int j,
               vector<vector<int>>& triangle,
               vector<vector<int>>& dp) {

        int n = triangle.size();

        if (i == n - 1)
            return triangle[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = helper(i + 1, j, triangle, dp);
        int diagonal = helper(i + 1, j + 1, triangle, dp);

        return dp[i][j] =
            triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helper(0, 0, triangle, dp);
    }
};