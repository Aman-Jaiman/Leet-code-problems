#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans(numRows);

        for(int i = 0; i < numRows; i++) {

            // Create row of size i+1 filled with 1
            ans[i] = vector<int>(i + 1, 1);

            // Fill middle values
            for(int j = 1; j < i; j++) {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }

        return ans;
    }
};
