#include<bits/stdc++.h>
using namespace std;

/*
===============================================================
LeetCode 714 - Best Time to Buy and Sell Stock with Transaction Fee
===============================================================

Approach 1 : Optimal with Variables
Time  : O(N)
Space : O(1)

Approach 2 : Space Optimized DP
Time  : O(N)
Space : O(1)

Approach 3 : Tabulation (Bottom-Up DP)
Time  : O(N)
Space : O(N)

Approach 4 : Memoization (Top-Down DP)
Time  : O(N)
Space : O(N)
*/


//===============================================================
// 1. Optimal with Variables
//===============================================================

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        int prevBuy = 0;
        int prevNotBuy = 0;

        int currBuy, currNotBuy;

        for (int i = n - 1; i >= 0; i--) {

            currBuy = max(
                -prices[i] - fee + prevNotBuy,
                prevBuy
            );

            currNotBuy = max(
                prices[i] + prevBuy,
                prevNotBuy
            );

            prevBuy = currBuy;
            prevNotBuy = currNotBuy;
        }

        return prevBuy;
    }
};


//===============================================================
// 2. Space Optimized DP
//===============================================================

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<int> ahead(2, 0), curr(2, 0);

        for (int i = n - 1; i >= 0; i--) {

            curr[1] = max(
                -prices[i] - fee + ahead[0],
                ahead[1]
            );

            curr[0] = max(
                prices[i] + ahead[1],
                ahead[0]
            );

            ahead = curr;
        }

        return ahead[1];
    }
};


//===============================================================
// 3. Tabulation (Bottom-Up DP)
//===============================================================

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {

            dp[i][1] = max(
                -prices[i] - fee + dp[i + 1][0],
                dp[i + 1][1]
            );

            dp[i][0] = max(
                prices[i] + dp[i + 1][1],
                dp[i + 1][0]
            );
        }

        return dp[0][1];
    }
};


//===============================================================
// 4. Memoization (Top-Down DP)
//===============================================================

class Solution {
public:

    // buy = 1 -> Can Buy
    // buy = 0 -> Holding Stock (Can Sell)

    int f(int i, int buy, int fee,
          vector<int>& prices,
          vector<vector<int>>& dp) {

        if (i >= prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy) {

            return dp[i][buy] = max(
                -prices[i] - fee + f(i + 1, 0, fee, prices, dp),
                f(i + 1, 1, fee, prices, dp)
            );
        }

        return dp[i][buy] = max(
            prices[i] + f(i + 1, 1, fee, prices, dp),
            f(i + 1, 0, fee, prices, dp)
        );
    }

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, fee, prices, dp);
    }
};