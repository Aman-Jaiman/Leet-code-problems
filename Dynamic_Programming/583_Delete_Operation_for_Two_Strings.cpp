#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    
    // 1. SPACE OPTIMIZED (LCS)
    // Time  : O(m * n)
    // Space : O(n)
    int minDistance(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (word1[i - 1] == word2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }

            prev = curr;
        }

        int lcs = prev[n];

        return (m - lcs) + (n - lcs);
    }


    // 2. TABULATION (LCS)
    // Time  : O(m * n)
    // Space : O(m * n)
    int minDistance_Tabulation(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int lcs = dp[m][n];

        return (m - lcs) + (n - lcs);
    }

    
    // 3. MEMOIZATION (LCS)
    // Time  : O(m * n)
    // Space : O(m * n) + Recursion Stack
    
    int LCS(int i, int j, string &word1, string &word2,
            vector<vector<int>> &dp) {

        if (i == word1.size() || j == word2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = 1 + LCS(i + 1, j + 1, word1, word2, dp);

        return dp[i][j] = max(
            LCS(i + 1, j, word1, word2, dp),
            LCS(i, j + 1, word1, word2, dp));
    }

    int minDistance_Memoization(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int lcs = LCS(0, 0, word1, word2, dp);

        return (m - lcs) + (n - lcs);
    }
};