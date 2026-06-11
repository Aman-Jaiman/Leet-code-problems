#include <bits/stdc++.h>
using namespace std;


// =========================
// 1. Memoization
// =========================
class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int i) {
        if (i < 0) return 0;

        if (dp[i] != -1) return dp[i];

        return dp[i] = max(
            helper(nums, dp, i - 1),
            nums[i] + helper(nums, dp, i - 2)
        );
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return helper(nums, dp, n - 1);
    }
};

// =========================
// 2. Tabulation
// =========================
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[n - 1];
    }
};

// =========================
// 3. Space Optimized
// =========================
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int prev1=nums[0];
        int prev2=max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            int curr=max(prev1+nums[i], prev2);
            prev1=prev2;
            prev2=curr;
        }

        return prev2;
    }
};