#include <bits/stdc++.h>
using namespace std;

// Memoization
class SolutionMemoization {
public:
    int f(int i, int j, string &w1, string &w2, vector<vector<int>> &dp) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (w1[i] == w2[j])
            return dp[i][j] = f(i - 1, j - 1, w1, w2, dp);

        int remove = f(i - 1, j, w1, w2, dp) + 1;
        int replace = f(i - 1, j - 1, w1, w2, dp) + 1;
        int insert = f(i, j - 1, w1, w2, dp) + 1;

        return dp[i][j] = min({remove, replace, insert});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n - 1, m - 1, word1, word2, dp);
    }
};

// Tabulation
class SolutionTabulation {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = i;

        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int remove = dp[i - 1][j] + 1;
                    int replace = dp[i - 1][j - 1] + 1;
                    int insert = dp[i][j - 1] + 1;

                    dp[i][j] = min({remove, replace, insert});
                }
            }
        }

        return dp[n][m];
    }
};

// Space Optimization
class SolutionSpaceOptimized {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int j = 0; j <= m; j++)
            prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i;

            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    int remove = prev[j] + 1;
                    int replace = prev[j - 1] + 1;
                    int insert = curr[j - 1] + 1;

                    curr[j] = min({remove, replace, insert});
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};