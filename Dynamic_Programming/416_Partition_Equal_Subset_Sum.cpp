#include <bits/stdc++.h>
using namespace std;

// ====================
// Space Optimized O(target)
// ====================
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        if (sum % 2)
            return false;

        int target = sum / 2;

        vector<bool> prev(target + 1, false);

        prev[0] = true;

        if (nums[0] <= target)
            prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {

            vector<bool> curr(target + 1, false);
            curr[0] = true;

            for (int t = 1; t <= target; t++) {

                bool notTake = prev[t];

                bool take = false;
                if (nums[i] <= t)
                    take = prev[t - nums[i]];

                curr[t] = take || notTake;
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
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        if (sum % 2)
            return false;

        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base case
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {

            for (int t = 1; t <= target; t++) {

                bool notTake = dp[i - 1][t];

                bool take = false;
                if (nums[i] <= t)
                    take = dp[i - 1][t - nums[i]];

                dp[i][t] = take || notTake;
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
    vector<vector<int>> dp;
    vector<int> nums;

    bool helper(int ind, int target) {

        if (target == 0)
            return true;

        if (ind == 0)
            return nums[0] == target;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notTake = helper(ind - 1, target);

        bool take = false;
        if (nums[ind] <= target)
            take = helper(ind - 1, target - nums[ind]);

        return dp[ind][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        this->nums = nums;

        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        if (sum % 2)
            return false;

        int target = sum / 2;

        dp.assign(n, vector<int>(target + 1, -1));

        return helper(n - 1, target);
    }
};