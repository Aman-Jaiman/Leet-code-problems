#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    void topoSort(int node,
                  vector<vector<pair<int,int>>> &adj,
                  vector<int> &vis,
                  stack<int> &st) {

        vis[node] = 1;

        for (auto &[next, wt] : adj[node]) {
            if (!vis[next]) {
                topoSort(next, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        vector<int> dist(V, 1e9);
        dist[0] = 0;

        while (!st.empty()) {

            int node = st.top();
            st.pop();

            if (dist[node] == 1e9) continue;

            for (auto &[next, wt] : adj[node]) {

                if (dist[node] + wt < dist[next]) {
                    dist[next] = dist[node] + wt;
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
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
    vector<int> ans = obj.shortestPath(V, E, edges);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}