#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Space Optimized (Using LPS)
// Time  : O(n^2)
// Space : O(n)

class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        int lps = prev[n];
        return n - lps;
    }
};


// Approach 2 : Tabulation
// Time  : O(n^2)
// Space : O(n^2)

class Solution2 {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int lps = dp[n][n];
        return n - lps;
    }
};


// Approach 3 : Memoization
// Time  : O(n^2)
// Space : O(n^2) + O(n)


class Solution3 {
public:
    int f(int i, int j, string &s, vector<vector<int>> &dp) {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = f(i + 1, j - 1, s, dp);

        return dp[i][j] = 1 + min(f(i + 1, j, s, dp),
                                  f(i, j - 1, s, dp));
    }

    int minInsertions(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, n - 1, s, dp);
    }
};