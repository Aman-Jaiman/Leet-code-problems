#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Start or end blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        queue<pair<int, int>> q;

        // Distance matrix
        vector<vector<int>> dist(n, vector<int>(n, -1));

        // 8 directions
        int drow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        q.push({0, 0});

        // Starting cell distance = 1
        dist[0][0] = 1;

        while (!q.empty()) {

            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            // Reached destination
            if (row == n - 1 && col == n - 1) {
                return dist[row][col];
            }

            // Explore 8 directions
            for (int i = 0; i < 8; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 &&
                    dist[nrow][ncol] == -1) {

                    dist[nrow][ncol] = dist[row][col] + 1;

                    q.push({nrow, ncol});
                }
            }
        }

        // No path exists
        return -1;
    }
};

int main() {

    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}
    };

    Solution obj;

    int ans = obj.shortestPathBinaryMatrix(grid);

    cout << "Shortest Path Length: " << ans << endl;

    return 0;
}