#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>, int>> q;

        // Push all rotten oranges into queue
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 2) {

                    q.push({{i, j}, 0});
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        int ans = 0;

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            int row = node.first.first;
            int col = node.first.second;
            int time = node.second;

            ans = max(ans, time);

            for(int i = 0; i < 4; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < m &&
                   ncol >= 0 && ncol < n &&
                   grid[nrow][ncol] == 1) {

                    grid[nrow][ncol] = 2;

                    q.push({{nrow, ncol}, time + 1});
                }
            }
        }

        // Check if any fresh orange remains
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {

                    return -1;
                }
            }
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    Solution obj;

    cout << "Minimum Time: "
         << obj.orangesRotting(grid);

    return 0;
}