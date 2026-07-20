/*
==========================================================
LeetCode 123. Best Time to Buy and Sell Stock III

Approaches:
1. Recursion
2. Memoization (Top Down DP)
3. Tabulation (Bottom Up DP)
4. Space Optimized DP

Time Complexity:
Recursion       : O(2^N)
Memoization     : O(N * 2 * 3)
Tabulation      : O(N * 2 * 3)
Space Optimized : O(2 * 3)

Space Complexity:
Recursion       : O(N)
Memoization     : O(N * 2 * 3)
Tabulation      : O(N * 2 * 3)
Space Optimized : O(2 * 3)
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;


//==========================================================
// 1. RECURSION
//==========================================================

class SolutionRecursion {
public:

    int f(int i, int buy, int cap, vector<int>& prices) {

        if (i == prices.size() || cap == 0)
            return 0;

        if (buy) {

            return max(
                -prices[i] + f(i + 1, 0, cap, prices),
                f(i + 1, 1, cap, prices)
            );
        }

        return max(
            prices[i] + f(i + 1, 1, cap - 1, prices),
            f(i + 1, 0, cap, prices)
        );
    }

    int maxProfit(vector<int>& prices) {
        return f(0, 1, 2, prices);
    }
};


//==========================================================
// 2. MEMOIZATION
//==========================================================

class SolutionMemoization {
public:

    int f(int i,
          int buy,
          int cap,
          vector<int>& prices,
          vector<vector<vector<int>>>& dp) {

        if (i == prices.size() || cap == 0)
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        if (buy) {

            return dp[i][buy][cap] = max(
                -prices[i] + f(i + 1, 0, cap, prices, dp),
                f(i + 1, 1, cap, prices, dp)
            );
        }

        return dp[i][buy][cap] = max(
            prices[i] + f(i + 1, 1, cap - 1, prices, dp),
            f(i + 1, 0, cap, prices, dp)
        );
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(3, -1))
        );

        return f(0, 1, 2, prices, dp);
    }
};


//==========================================================
// 3. TABULATION
//==========================================================

class SolutionTabulation {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(3, 0))
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int buy = 0; buy <= 1; buy++) {

                for (int cap = 1; cap <= 2; cap++) {

                    if (buy) {

                        dp[i][buy][cap] = max(
                            -prices[i] + dp[i + 1][0][cap],
                            dp[i + 1][1][cap]
                        );
                    }
                    else {

                        dp[i][buy][cap] = max(
                            prices[i] + dp[i + 1][1][cap - 1],
                            dp[i + 1][0][cap]
                        );
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};


//==========================================================
// 4. SPACE OPTIMIZATION
//==========================================================

class SolutionSpaceOptimized {
public:

    int maxProfit(vector<int>& prices) {

        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        int n = prices.size();

        for (int i = n - 1; i >= 0; i--) {

            for (int buy = 0; buy <= 1; buy++) {

                for (int cap = 1; cap <= 2; cap++) {

                    if (buy) {

                        curr[buy][cap] = max(
                            -prices[i] + ahead[0][cap],
                            ahead[1][cap]
                        );
                    }
                    else {

                        curr[buy][cap] = max(
                            prices[i] + ahead[1][cap - 1],
                            ahead[0][cap]
                        );
                    }
                }
            }

            ahead = curr;
        }

        return ahead[1][2];
    }
};


//==========================================================
// Driver Code (Optional)
//==========================================================

int main() {

    vector<int> prices = {3,3,5,0,0,3,1,4};

    SolutionRecursion r;
    SolutionMemoization m;
    SolutionTabulation t;
    SolutionSpaceOptimized s;

    cout << "Recursion       : " << r.maxProfit(prices) << endl;
    cout << "Memoization     : " << m.maxProfit(prices) << endl;
    cout << "Tabulation      : " << t.maxProfit(prices) << endl;
    cout << "Space Optimized : " << s.maxProfit(prices) << endl;

    return 0;
}