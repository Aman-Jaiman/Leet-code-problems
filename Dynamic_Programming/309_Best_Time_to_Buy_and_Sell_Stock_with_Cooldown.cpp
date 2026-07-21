#include<bits/stdc++.h>
using namespace std;


//===============================================================
// 1. Optimal with Variables
// Time : O(N)
// Space: O(1)
//===============================================================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<int> front1(2, 0); // dp[i+1]
        vector<int> front2(2, 0); // dp[i+2]
        vector<int> curr(2, 0);

        for (int i = n - 1; i >= 0; i--) {

            curr[1] = max(
                -prices[i] + front1[0],   // Buy
                front1[1]                 // Skip
            );

            curr[0] = max(
                prices[i] + front2[1],    // Sell + Cooldown
                front1[0]                 // Hold
            );

            front2 = front1;
            front1 = curr;
        }

        return front1[1];
    }
};


//===============================================================
// 2. Space Optimized DP
// Time : O(N)
// Space: O(1)
//===============================================================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> ahead1(1, vector<int>(2, 0));
        vector<vector<int>> ahead2(1, vector<int>(2, 0));
        vector<vector<int>> curr(1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {

            curr[0][1] = max(
                -prices[i] + ahead1[0][0],
                ahead1[0][1]
            );

            curr[0][0] = max(
                prices[i] + ahead2[0][1],
                ahead1[0][0]
            );

            ahead2 = ahead1;
            ahead1 = curr;
        }

        return ahead1[0][1];
    }
};


//===============================================================
// 3. Tabulation (Bottom-Up DP)
// Time : O(N)
// Space: O(N)
//===============================================================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {

            dp[i][1] = max(
                -prices[i] + dp[i + 1][0],
                dp[i + 1][1]
            );

            dp[i][0] = max(
                prices[i] + dp[i + 2][1],
                dp[i + 1][0]
            );
        }

        return dp[0][1];
    }
};


//===============================================================
// 4. Memoization (Top-Down DP)
// Time : O(N)
// Space: O(N)
//===============================================================

class Solution {
public:

    // buy = 1 -> Can Buy
    // buy = 0 -> Holding Stock (Can Sell)

    int f(int i, int buy,
          vector<int>& prices,
          vector<vector<int>>& dp) {

        if (i >= prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        if (buy) {

            profit = max(
                -prices[i] + f(i + 1, 0, prices, dp),
                f(i + 1, 1, prices, dp)
            );

        } else {

            profit = max(
                prices[i] + f(i + 2, 1, prices, dp), // Cooldown
                f(i + 1, 0, prices, dp)
            );
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, prices, dp);
    }
};