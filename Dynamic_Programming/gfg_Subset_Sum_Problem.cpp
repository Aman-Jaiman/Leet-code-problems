#include <bits/stdc++.h>
using namespace std;


// ====================
// Space Optimized O(sum)
// ====================
class Solution {
public:

    bool isSubsetSum(vector<int>& arr, int sum) {


        int n = arr.size();


        vector<bool> prev(sum + 1, false);


        // Base case
        prev[0] = true;


        if (arr[0] <= sum)
            prev[arr[0]] = true;



        for (int i = 1; i < n; i++) {


            vector<bool> curr(sum + 1, false);


            curr[0] = true;



            for (int target = 1; target <= sum; target++) {


                bool notTake = prev[target];


                bool take = false;


                if (arr[i] <= target) {

                    take = prev[target - arr[i]];
                }



                curr[target] = take || notTake;
            }



            prev = curr;
        }



        return prev[sum];
    }
};




// ====================
// Tabulation O(n*sum)
// ====================
class Solution {
public:

    bool isSubsetSum(vector<int>& arr, int sum) {


        int n = arr.size();



        vector<vector<bool>> dp(
            n,
            vector<bool>(sum + 1, false)
        );



        // Base case
        for (int i = 0; i < n; i++) {

            dp[i][0] = true;
        }



        if (arr[0] <= sum)
            dp[0][arr[0]] = true;



        for (int i = 1; i < n; i++) {


            for (int target = 1; target <= sum; target++) {



                bool notTake = dp[i - 1][target];



                bool take = false;


                if (arr[i] <= target) {

                    take = dp[i - 1][target - arr[i]];
                }




                dp[i][target] = take || notTake;
            }
        }




        return dp[n - 1][sum];
    }
};






// ====================
// Memoization
// ====================
class Solution {
public:


    bool helper(int i,
                int sum,
                vector<int>& arr,
                vector<vector<int>>& dp) {



        // Base case
        if (sum == 0)
            return true;



        if (i == 0) {

            return arr[0] == sum;
        }




        if (dp[i][sum] != -1)
            return dp[i][sum];




        bool notTake = helper(i - 1,
                              sum,
                              arr,
                              dp);




        bool take = false;



        if (arr[i] <= sum) {


            take = helper(i - 1,
                          sum - arr[i],
                          arr,
                          dp);
        }




        return dp[i][sum] = take || notTake;
    }






    bool isSubsetSum(vector<int>& arr, int sum) {



        int n = arr.size();




        vector<vector<int>> dp(
            n,
            vector<int>(sum + 1, -1)
        );




        return helper(n - 1,
                      sum,
                      arr,
                      dp);
    }
};