#include <bits/stdc++.h>
using namespace std;

// Using Table form (bottom up ) approch 
// TC: O(n) SC: O(1)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int prev2=1;
        int prev=2;
        for(int i=3;i<=n;i++){
            int curr=prev2+prev;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};

// Using Table form (bottom up ) approch 
// TC: O(n) SC: O(n)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        vector<int> dp(n + 1, -1);
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};


// Using Recurssion (Top Down/ Up Down ) approch
// TC: O(n) SC: O(n+n
class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if (n <= 2) return dp[n];

        if (dp[n] != -1) return dp[n];

        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }

    int climbStairs(int n) {
        if (n == 1) return 1;

        vector<int> dp(n + 1, -1);
        dp[1] = 1;
        dp[2] = 2;

        return helper(n, dp);
    }
};
