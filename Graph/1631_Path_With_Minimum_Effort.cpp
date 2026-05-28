#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        // Directions: left, up, right, down
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};

        // Min Heap
        // {effort, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        // Distance matrix
        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        // Start from (0,0)
        pq.push({0, {0,0}});

        dist[0][0] = 0;

        while (!pq.empty()) {

            auto node = pq.top();
            pq.pop();

            int effort = node.first;
            int row = node.second.first;
            int col = node.second.second;

            // Reached destination
            if (row == m - 1 && col == n - 1) {
                return effort;
            }

            // Explore 4 directions
            for (int i = 0; i < 4; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < m &&
                    ncol >= 0 && ncol < n) {

                    int diff = abs(
                        heights[nrow][ncol] -
                        heights[row][col]
                    );

                    // Maximum effort in the path
                    int newEffort = max(effort, diff);

                    // Relaxation
                    if (newEffort < dist[nrow][ncol]) {

                        dist[nrow][ncol] = newEffort;

                        pq.push({
                            newEffort,
                            {nrow, ncol}
                        });
                    }
                }
            }
        }

        return -1;
    }
};

int main() {

    vector<vector<int>> heights = {
        {1,2,2},
        {3,8,2},
        {5,3,5}
    };

    Solution obj;

    int ans = obj.minimumEffortPath(heights);

    cout << "Minimum Effort Path: "
         << ans << endl;

    return 0;
}