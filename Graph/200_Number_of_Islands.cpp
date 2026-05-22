#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<char>>& grid,
             int row,
             int col) {

        grid[row][col] = '#';

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 &&
                ncol >= 0 &&
                nrow < grid.size() &&
                ncol < grid[0].size() &&
                grid[nrow][ncol] == '1') {

                dfs(grid, nrow, ncol);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {

                    dfs(grid, i, j);

                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << obj.numIslands(grid);

    return 0;
}