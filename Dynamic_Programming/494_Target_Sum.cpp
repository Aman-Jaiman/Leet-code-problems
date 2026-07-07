#include <bits/stdc++.h>
using namespace std;


// ====================
// Space Optimized O(sum)
// Subset Sum Conversion
// ====================
class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {

        int total = accumulate(nums.begin(),
                               nums.end(),
                               0);


        if (abs(target) > total ||
            (total + target) % 2)
            return 0;


        int sum = (total + target) / 2;


        vector<int> dp(sum + 1, 0);


        dp[0] = 1;


        for (int num : nums) {

            for (int j = sum; j >= num; j--) {

                dp[j] += dp[j - num];
            }
        }


        return dp[sum];
    }
};



// ====================
// Tabulation O(n*2001)
// Using +1000 Offset
// ====================
class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();


        vector<vector<int>> dp(
            n + 1,
            vector<int>(2001, 0)
        );


        // sum = 0 stored at index 1000
        dp[n][1000] = 1;


        for (int i = n - 1; i >= 0; i--) {

            for (int sum = -1000; sum <= 1000; sum++) {


                if (dp[i + 1][sum + 1000] != 0) {


                    int add = sum + nums[i];

                    int sub = sum - nums[i];


                    dp[i][add + 1000] +=
                        dp[i + 1][sum + 1000];


                    dp[i][sub + 1000] +=
                        dp[i + 1][sum + 1000];
                }
            }
        }


        if (target > 1000 || target < -1000)
            return 0;


        return dp[0][target + 1000];
    }
};



// ====================
// Memoization O(n*2001)
// Using +1000 Offset
// ====================
class Solution {
public:


    int helper(int i,
               vector<vector<int>>& dp,
               int sum,
               int target,
               vector<int>& nums) {


        int n = nums.size();


        if (i == n) {

            if (sum == target)
                return 1;


            return 0;
        }



        if (dp[i][sum + 1000] != -1)
            return dp[i][sum + 1000];



        int add = helper(i + 1,
                         dp,
                         sum + nums[i],
                         target,
                         nums);



        int sub = helper(i + 1,
                         dp,
                         sum - nums[i],
                         target,
                         nums);



        return dp[i][sum + 1000] = add + sub;
    }



    int findTargetSumWays(vector<int>& nums,
                          int target) {


        int n = nums.size();


        vector<vector<int>> dp(
            n,
            vector<int>(2001, -1)
        );


        return helper(0,
                      dp,
                      0,
                      target,
                      nums);
    }
};