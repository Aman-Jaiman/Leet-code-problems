#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        // Top and bottom rows
        for (int j = 0; j < n; j++) {

            if (grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = -1;
            }

            if (grid[m-1][j] == 1) {
                q.push({m-1, j});
                grid[m-1][j] = -1;
            }
        }

        // Left and right columns
        for (int i = 0; i < m; i++) {

            if (grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = -1;
            }

            if (grid[i][n-1] == 1) {
                q.push({i, n-1});
                grid[i][n-1] = -1;
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // BFS
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
                    grid[nrow][ncol] == 1) {

                    grid[nrow][ncol] = -1;

                    q.push({nrow, ncol});
                }
            }
        }

        // Count remaining land cells
        int ans = 0;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    cout << obj.numEnclaves(grid);

    return 0;
}