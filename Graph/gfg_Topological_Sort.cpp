#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        // Build graph
        for (auto e : edges) {

            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        // Push all nodes having indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        // Kahn's Algorithm
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto it : adj[node]) {

                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }
};

int main() {

    int V = 6;

    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    Solution obj;

    vector<int> ans = obj.topoSort(V, edges);

    cout << "Topological Sort: ";

    for (auto it : ans) {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}