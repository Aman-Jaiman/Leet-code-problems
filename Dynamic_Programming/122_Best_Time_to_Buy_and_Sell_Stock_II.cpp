#include<bits/stdc++.h>
using namespace std;


//1. optimal with Variable 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prevBuy, prevNotBuy, curBuy, curNotBuy;
        prevBuy =0;
        prevNotBuy =0;

        for(int i=n-1; i>=0; i--){
            curBuy = max( -prices[i]+ prevNotBuy, 0+ prevBuy);
            curNotBuy = max(prices[i] + prevBuy, 0 + prevNotBuy);

            prevBuy = curBuy;
            prevNotBuy = curNotBuy; 
        }

        return prevBuy;
    }
};

//1.Space Optimized DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> ahead(2, 0), curr(2, 0);

        for (int i = prices.size() - 1; i >= 0; i--) {
            curr[1] = max(-prices[i] + ahead[0],
                          ahead[1]);

            curr[0] = max(prices[i] + ahead[1],
                          ahead[0]);

            ahead = curr;
        }

        return ahead[1];
    }
};


//2. Tabulation (Bottom-Up DP)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][1] = max(-prices[i] + dp[i + 1][0],
                           dp[i + 1][1]);

            dp[i][0] = max(prices[i] + dp[i + 1][1],
                           dp[i + 1][0]);
        }

        return dp[0][1];
    }
};

//3. Memoization (Top-Down DP)
class Solution {
public:
    
    // 0 --> not Buy
    // 1 --> Buy
    int f(int i, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(i == prices.size()){
            return 0;
        }

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        if(buy){
            profit = max( -prices[i] + f(i+1, 0, prices, dp), 0 + f(i+1, 1, prices, dp));
        }

        else {
            profit = max( prices[i] + f(i+1, 1, prices, dp), 0 + f(i+1, 0, prices, dp));
        }

        return dp[i][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int> (2, -1));

        return f(0, 1, prices, dp);
    }
};