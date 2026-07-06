#include <bits/stdc++.h>
using namespace std;


// ====================
// Space Optimized O(amount)
// ====================
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, 1e9);

        dp[0] = 0;

        for (int coin : coins) {

            for (int t = coin; t <= amount; t++) {

                dp[t] = min(dp[t], 1 + dp[t - coin]);
            }
        }

        if (dp[amount] >= 1e9)
            return -1;

        return dp[amount];
    }
};


// ====================
// Tabulation O(n*amount)
// ====================
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(
            n, vector<int>(amount + 1, 1e9)
        );


        // Base case
        for (int t = 0; t <= amount; t++) {

            if (t % coins[0] == 0)
                dp[0][t] = t / coins[0];
        }


        for (int i = 1; i < n; i++) {

            for (int t = 0; t <= amount; t++) {

                int notTake = dp[i - 1][t];

                int take = 1e9;

                if (coins[i] <= t)
                    take = 1 + dp[i][t - coins[i]];

                dp[i][t] = min(take, notTake);
            }
        }


        if (dp[n - 1][amount] >= 1e9)
            return -1;

        return dp[n - 1][amount];
    }
};


// ====================
// Memoization
// ====================
class Solution {
public:

    int helper(int i, int amount,
               vector<int>& coins,
               vector<vector<int>>& dp) {


        if (i == 0) {

            if (amount % coins[0] == 0)
                return amount / coins[0];

            return 1e9;
        }


        if (dp[i][amount] != -1)
            return dp[i][amount];


        int notTake = helper(i - 1,
                             amount,
                             coins,
                             dp);


        int take = 1e9;

        if (coins[i] <= amount) {

            take = 1 + helper(i,
                              amount - coins[i],
                              coins,
                              dp);
        }


        return dp[i][amount] = min(take, notTake);
    }


    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(
            n,
            vector<int>(amount + 1, -1)
        );


        int ans = helper(n - 1,
                         amount,
                         coins,
                         dp);


        if (ans >= 1e9)
            return -1;

        return ans;
    }
};