#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool bfs(int start,
             vector<vector<int>>& graph,
             vector<int>& color) {

        queue<int> q;

        q.push(start);

        color[start] = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto neigh : graph[node]) {

                // If neighbor is uncolored
                if (color[neigh] == -1) {

                    color[neigh] = !color[node];

                    q.push(neigh);
                }

                // Same color found
                else if (color[neigh] == color[node]) {

                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n, -1);

        // Handle disconnected components
        for (int i = 0; i < n; i++) {

            if (color[i] == -1) {

                if (!bfs(i, graph, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    if (obj.isBipartite(graph)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}