#include <bits/stdc++.h>
using namespace std;


// ====================
// Space Optimized O(m)
// ====================
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {


        int n = text1.size();
        int m = text2.size();



        vector<int> prev(m + 1, 0);



        for (int i = 1; i <= n; i++) {


            vector<int> curr(m + 1, 0);



            for (int j = 1; j <= m; j++) {



                if (text1[i - 1] == text2[j - 1]) {


                    curr[j] = 1 + prev[j - 1];
                }


                else {


                    curr[j] = max(prev[j],
                                  curr[j - 1]);
                }
            }



            prev = curr;
        }




        return prev[m];
    }
};







// ====================
// Tabulation O(n*m)
// ====================
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {


        int n = text1.size();
        int m = text2.size();




        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );




        // Base case already handled by 0



        for (int i = 1; i <= n; i++) {


            for (int j = 1; j <= m; j++) {




                if (text1[i - 1] == text2[j - 1]) {


                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }



                else {


                    dp[i][j] = max(dp[i - 1][j],
                                   dp[i][j - 1]);
                }
            }
        }





        return dp[n][m];
    }
};









// ====================
// Memoization
// ====================
class Solution {
public:


    int helper(int i,
               int j,
               string& text1,
               string& text2,
               vector<vector<int>>& dp) {




        if (i < 0 || j < 0)
            return 0;




        if (dp[i][j] != -1)
            return dp[i][j];





        if (text1[i] == text2[j]) {


            return dp[i][j] =
                   1 + helper(i - 1,
                              j - 1,
                              text1,
                              text2,
                              dp);
        }






        return dp[i][j] =
               max(helper(i - 1,
                          j,
                          text1,
                          text2,
                          dp),


                   helper(i,
                          j - 1,
                          text1,
                          text2,
                          dp));
    }






    int longestCommonSubsequence(string text1, string text2) {



        int n = text1.size();
        int m = text2.size();





        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );





        return helper(n - 1,
                      m - 1,
                      text1,
                      text2,
                      dp);
    }
};