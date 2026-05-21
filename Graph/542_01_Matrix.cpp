#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> res(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        // Push all 0 cells into queue
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 0) {

                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // Multi-source BFS
        while (!q.empty()) {

            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            for (int i = 0; i < 4; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 &&
                    ncol >= 0 &&
                    nrow < m &&
                    ncol < n &&
                    res[nrow][ncol] == -1) {

                    res[nrow][ncol] =
                        res[row][col] + 1;

                    q.push({nrow, ncol});
                }
            }
        }

        return res;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> ans =
        obj.updateMatrix(mat);

    for (auto row : ans) {

        for (auto val : row) {
            cout << val << " ";
        }

        cout << endl;
    }

    return 0;
}