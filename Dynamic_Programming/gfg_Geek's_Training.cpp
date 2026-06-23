#include <bits/stdc++.h>
using namespace std;

//space 1
class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<int> prev(3);

        prev[0] = mat[0][0];
        prev[1] = mat[0][1];
        prev[2] = mat[0][2];

        for (int day = 1; day < n; day++) {
            vector<int> curr(3);

            curr[0] = mat[day][0] + max(prev[1], prev[2]);
            curr[1] = mat[day][1] + max(prev[0], prev[2]);
            curr[2] = mat[day][2] + max(prev[0], prev[1]);

            prev = curr;
        }

        return max({prev[0], prev[1], prev[2]});
    }
};


// memorization
class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(3, 0));

        // Base case
        dp[0][0] = mat[0][0];
        dp[0][1] = mat[0][1];
        dp[0][2] = mat[0][2];

        for (int day = 1; day < n; day++) {
            dp[day][0] = mat[day][0] + max(dp[day - 1][1], dp[day - 1][2]);
            dp[day][1] = mat[day][1] + max(dp[day - 1][0], dp[day - 1][2]);
            dp[day][2] = mat[day][2] + max(dp[day - 1][0], dp[day - 1][1]);
        }

        return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};


// recursion 
class Solution {
public:
    int helper(int day, int last,
               vector<vector<int>>& mat,
               vector<vector<int>>& dp) {

        if (day == mat.size()) return 0;

        if (dp[day][last] != -1)
            return dp[day][last];

        int ans = 0;

        for (int task = 0; task < 3; task++) {
            if (task != last) {
                ans = max(ans,
                          mat[day][task] +
                          helper(day + 1, task, mat, dp));
            }
        }

        return dp[day][last] = ans;
    }

    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(4, -1));

        return helper(0, 3, mat, dp);
    }
};