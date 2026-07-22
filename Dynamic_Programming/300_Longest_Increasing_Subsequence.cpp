#include<bits/stdc++.h>
using namespace std;

// memorization
class Solution {
public:

    int f(int i , int prev, vector<int> &nums, vector<vector<int>> &dp){

        if(i == nums.size()) return 0;

        if(dp[i][prev +1] != -1) dp[i][prev +1];

        // not Take ;
        int len = 0 + f(i+1, prev, nums, dp);

        if(prev == -1 || nums[i] > nums[prev]){
            return dp[i][prev+1] = max(len, 1 + f(i+1, i, nums, dp));
        }
        return dp[i][prev+1] = len;
    }
     
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n +1, -1));
        return f(0, -1, nums, dp);
    }
};

// better solution 
//tabulation without extra calling space
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // dp[i][prev+1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Base case:
        // dp[n][*] = 0 (already initialized)

        for (int i = n - 1; i >= 0; i--) {

            // prev can only be -1 to i-1
            for (int prev = i - 1; prev >= -1; prev--) {

                // Not Take
                int notTake = dp[i + 1][prev + 1];

                // Take
                int take = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + dp[i + 1][i + 1];
                }

                dp[i][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};


// optimal soution
// O(n.log(n)) time
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> arr;

        for (int x : nums) {

            if (arr.empty() || x > arr.back()) {
                arr.push_back(x);
            } else {
                int lb = 0;
                int ub = arr.size() - 1;

                while (lb < ub) {
                    int mid = lb + (ub - lb) / 2;

                    if (arr[mid] >= x)
                        ub = mid;
                    else
                        lb = mid + 1;
                }

                arr[lb] = x;  
            }
        }

        return arr.size();
    }
};

