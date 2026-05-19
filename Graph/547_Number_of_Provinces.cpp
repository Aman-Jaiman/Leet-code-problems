#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<int>& vis, int node, vector<int> adj[]) {

        vis[node] = 1;

        for(auto it : adj[node]) {

            if(!vis[it]) {
                dfs(vis, it, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> adj[n];

        // Convert matrix to adjacency list
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(isConnected[i][j] == 1 && i != j) {

                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);

        int provinces = 0;

        for(int i = 0; i < n; i++) {

            if(!vis[i]) {

                provinces++;

                dfs(vis, i, adj);
            }
        }

        return provinces;
    }
};

int main() {

    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    Solution obj;

    cout << "Number of Provinces: "
         << obj.findCircleNum(isConnected);

    return 0;
}