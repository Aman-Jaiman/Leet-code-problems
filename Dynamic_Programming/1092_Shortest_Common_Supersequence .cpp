#include <bits/stdc++.h>
using namespace std;

//1. Recursion + Memoization (Stores String)
class Solution {
public:
    vector<vector<string>> dp;

    string solve(int i, int j, string &str1, string &str2) {

        if (i == str1.size())
            return str2.substr(j);

        if (j == str2.size())
            return str1.substr(i);

        if (dp[i][j] != "#")
            return dp[i][j];

        if (str1[i] == str2[j]) {
            return dp[i][j] = str1[i] + solve(i + 1, j + 1, str1, str2);
        }

        string takeStr1 = str1[i] + solve(i + 1, j, str1, str2);
        string takeStr2 = str2[j] + solve(i, j + 1, str1, str2);

        if (takeStr1.size() <= takeStr2.size())
            return dp[i][j] = takeStr1;

        return dp[i][j] = takeStr2;
    }

    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        dp.assign(n, vector<string>(m, "#"));

        return solve(0, 0, str1, str2);
    }
};

//2. Tabulation + Backtracking (Optimal)
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string ans = "";

        int i = n;
        int j = m;

        while (i > 0 && j > 0) {

            if (str1[i - 1] == str2[j - 1]) {

                ans += str1[i - 1];
                i--;
                j--;
            }

            else if (dp[i - 1][j] > dp[i][j - 1]) {

                ans += str1[i - 1];
                i--;
            }

            else {

                ans += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {

            ans += str1[i - 1];
            i--;
        }

        while (j > 0) {

            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

//3. LCS String + Merge
class Solution {
public:

    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string lcs = "";

        int i = n;
        int j = m;

        while (i > 0 && j > 0) {

            if (str1[i - 1] == str2[j - 1]) {

                lcs += str1[i - 1];
                i--;
                j--;
            }

            else if (dp[i - 1][j] > dp[i][j - 1])
                i--;

            else
                j--;
        }

        reverse(lcs.begin(), lcs.end());

        string ans = "";

        i = 0;
        j = 0;

        for (char ch : lcs) {

            while (str1[i] != ch)
                ans += str1[i++];

            while (str2[j] != ch)
                ans += str2[j++];

            ans += ch;
            i++;
            j++;
        }

        while (i < n)
            ans += str1[i++];

        while (j < m)
            ans += str2[j++];

        return ans;
    }
};