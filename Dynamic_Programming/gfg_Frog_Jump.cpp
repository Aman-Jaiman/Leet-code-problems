#include<bits/stdc++.h>
using namespace std;

// Using Memorization --> Tabulation (down --> top)
// TC: O(n)  and SC: O(n)
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int>dp(n,-1);
        dp[0]=0;
        for(int i=1;i<n;i++) {
            int left= dp[i-1]+abs(height[i]-height[i-1]);
            int right=INT_MAX;
            if(i>1) {
                right= dp[i-2]+abs(height[i]-height[i-2]);
            }
            dp[i]=min(left,right);
        }
        return dp[n-1];
    }
};

// Using Recursion --> Memorization (top --> down)
// TC: O(n) and SC: O(n)+O(n)
class Solution {
  public:
    int helper(int i, vector<int>& height, vector<int>&dp){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int left= helper(i-1,height,dp)+abs(height[i]-height[i-1]);
        int right=INT_MAX;
        if(i>1){
            right=helper(i-2,height,dp)+abs(height[i]-height[i-2]);
        }
        return dp[i] = min(left,right);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n,-1);
        return helper(n - 1, height, dp);
    }
};