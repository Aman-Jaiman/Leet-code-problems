#include <bits/stdc++.h>
using namespace std;

// ====================
// Space Optimized O(target)
// ====================
class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {

        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> prev(target + 1, 0);

        // Base case
        if (arr[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if (arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1;

        for (int i = 1; i < n; i++) {

            vector<int> curr(target + 1, 0);

            for (int t = 0; t <= target; t++) {

                int notTake = prev[t];

                int take = 0;
                if (arr[i] <= t)
                    take = prev[t - arr[i]];

                curr[t] = (take + notTake) % MOD;
            }

            prev = curr;
        }

        return prev[target];
    }
};


// ====================
// Tabulation O(n*target)
// ====================
class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {

        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base case
        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (arr[0] != 0 && arr[0] <= target)
            dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++) {

            for (int t = 0; t <= target; t++) {

                int notTake = dp[i - 1][t];

                int take = 0;
                if (arr[i] <= t)
                    take = dp[i - 1][t - arr[i]];

                dp[i][t] = (take + notTake) % MOD;
            }
        }

        return dp[n - 1][target];
    }
};


// ====================
// Memoization
// ====================
class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<vector<int>> dp;
    vector<int> arr;

    int helper(int ind, int target) {

        if (ind == 0) {

            if (target == 0 && arr[0] == 0)
                return 2;

            if (target == 0 || target == arr[0])
                return 1;

            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = helper(ind - 1, target);

        int take = 0;
        if (arr[ind] <= target)
            take = helper(ind - 1, target - arr[ind]);

        return dp[ind][target] = (take + notTake) % MOD;
    }

    int perfectSum(vector<int>& nums, int target) {

        arr = nums;

        int n = arr.size();

        dp.assign(n, vector<int>(target + 1, -1));

        return helper(n - 1, target);
    }
};