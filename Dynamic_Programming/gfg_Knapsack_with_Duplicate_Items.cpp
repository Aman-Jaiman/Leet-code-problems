#include <bits/stdc++.h>
using namespace std;


// ====================
// Memoization
// ====================
class Solution {
public:


    int f(int i,
          vector<int>& val,
          vector<int>& wt,
          int capacity,
          vector<vector<int>>& dp) {



        if (i == 0) {

            return (capacity / wt[0]) * val[0];
        }



        if (dp[i][capacity] != -1)
            return dp[i][capacity];



        int notTake = f(i - 1,
                        val,
                        wt,
                        capacity,
                        dp);



        int take = INT_MIN;


        if (wt[i] <= capacity) {

            take = val[i] + f(i,
                              val,
                              wt,
                              capacity - wt[i],
                              dp);
        }



        return dp[i][capacity] = max(take,
                                     notTake);
    }



    int knapSack(vector<int>& val,
                 vector<int>& wt,
                 int capacity) {


        int n = wt.size();


        vector<vector<int>> dp(
            n,
            vector<int>(capacity + 1, -1)
        );



        return f(n - 1,
                 val,
                 wt,
                 capacity,
                 dp);
    }
};