#include <bits/stdc++.h>
using namespace std;

// ====================
// Space Optimized O(target)
// ====================
class Solution {
public:
    int minDifference(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        vector<bool> prev(sum + 1, false);

        prev[0] = true;

        if (nums[0] <= sum)
            prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {

            vector<bool> curr(sum + 1, false);
            curr[0] = true;

            for (int target = 1; target <= sum; target++) {

                bool notTake = prev[target];

                bool take = false;
                if (nums[i] <= target)
                    take = prev[target - nums[i]];

                curr[target] = take || notTake;
            }

            prev = curr;
        }

        int ans = 1e9;

        for (int s1 = 0; s1 <= sum / 2; s1++) {
            if (prev[s1]) {
                int s2 = sum - s1;
                ans = min(ans, abs(s2 - s1));
            }
        }

        return ans;
    }
};


// ====================
// Tabulation O(n*target)
// ====================
class Solution {
public:
    int minDifference(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Base case
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= sum)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {

            for (int target = 1; target <= sum; target++) {

                bool notTake = dp[i - 1][target];

                bool take = false;
                if (nums[i] <= target)
                    take = dp[i - 1][target - nums[i]];

                dp[i][target] = take || notTake;
            }
        }

        int ans = 1e9;

        for (int s1 = 0; s1 <= sum / 2; s1++) {
            if (dp[n - 1][s1]) {
                int s2 = sum - s1;
                ans = min(ans, abs(s2 - s1));
            }
        }

        return ans;
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

    int minDifference(vector<int>& arr) {

        nums = arr;

        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        dp.assign(n, vector<int>(sum + 1, -1));

        int ans = 1e9;

        for (int s1 = 0; s1 <= sum / 2; s1++) {

            if (helper(n - 1, s1)) {

                int s2 = sum - s1;

                ans = min(ans, abs(s2 - s1));
            }
        }

        return ans;
    }
};