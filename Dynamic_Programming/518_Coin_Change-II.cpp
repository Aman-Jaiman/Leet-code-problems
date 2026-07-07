#include <bits/stdc++.h>
using namespace std;


// ====================
// Space Optimized O(amount)
// ====================
class Solution {
public:

    int change(int amount, vector<int>& coins) {


        vector<int> dp(amount + 1, 0);


        dp[0] = 1;


        for (int coin : coins) {

            for (int t = coin; t <= amount; t++) {

                dp[t] += dp[t - coin];
            }
        }


        return dp[amount];
    }
};



// ====================
// Tabulation O(n*amount)
// ====================
class Solution {
public:

    int change(int amount, vector<int>& coins) {


        int n = coins.size();


        vector<vector<int>> dp(
            n,
            vector<int>(amount + 1, 0)
        );


        // Base case
        for (int t = 0; t <= amount; t++) {

            if (t % coins[0] == 0)
                dp[0][t] = 1;
        }



        for (int i = 1; i < n; i++) {

            for (int t = 0; t <= amount; t++) {


                int notTake = dp[i - 1][t];


                int take = 0;


                if (coins[i] <= t) {

                    take = dp[i][t - coins[i]];
                }



                dp[i][t] = take + notTake;
            }
        }



        return dp[n - 1][amount];
    }
};



// ====================
// Memoization
// ====================
class Solution {
public:


    int helper(int i,
               int amount,
               vector<int>& coins,
               vector<vector<int>>& dp) {



        if (i == 0) {

            if (amount % coins[0] == 0)
                return 1;


            return 0;
        }



        if (dp[i][amount] != -1)
            return dp[i][amount];



        int notTake = helper(i - 1,
                             amount,
                             coins,
                             dp);



        int take = 0;


        if (coins[i] <= amount) {

            take = helper(i,
                          amount - coins[i],
                          coins,
                          dp);
        }



        return dp[i][amount] = take + notTake;
    }



    int change(int amount,
               vector<int>& coins) {


        int n = coins.size();


        vector<vector<int>> dp(
            n,
            vector<int>(amount + 1, -1)
        );



        return helper(n - 1,
                      amount,
                      coins,
                      dp);
    }
};