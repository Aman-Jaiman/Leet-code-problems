#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> vis(V, 0);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, 0});

        int mstWeight = 0;

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (vis[node]) continue;

            vis[node] = 1;
            mstWeight += wt;

            for (auto &[adjNode, edgeWt] : adj[node]) {
                if (!vis[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return mstWeight;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    Solution obj;
    cout << obj.spanningTree(V, edges) << endl;

    return 0;
}