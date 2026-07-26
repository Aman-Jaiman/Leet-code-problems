#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));

        int drow[] = {0, 0, 1, -1};
        int dcol[] = {1, -1, 0, 0};

        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        while(!dq.empty()){

            auto [row, col] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                int wt = (grid[row][col] == i +1) ? 0 : 1;

                if(nrow<0 || ncol<0 || nrow==m || ncol==n) continue;

                if(dist[nrow][ncol] > wt + dist[row][col]){
                    dist[nrow][ncol] = wt + dist[row][col];

                    if(wt == 0) dq.push_front({nrow, ncol});
                    else 
                    dq.push_back({nrow, ncol});
                }    
            }    
        }

        return dist[m-1][n-1];
    }
};