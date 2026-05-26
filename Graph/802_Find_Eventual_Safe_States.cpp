#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> adj(n);
        vector<int> out(n, 0);
        vector<int> ans;

        queue<int> q;

        // Build reverse graph and count outdegree
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < graph[i].size(); j++) {

                int neigh = graph[i][j];

                adj[neigh].push_back(i);

                out[i]++;
            }

            // Terminal node
            if (out[i] == 0) {
                q.push(i);
            }
        }

        // Kahn's Algorithm
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto it : adj[node]) {

                out[it]--;

                if (out[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> graph = {
        {1,2},
        {2,3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    vector<int> ans = obj.eventualSafeNodes(graph);

    cout << "Safe Nodes: ";

    for (auto it : ans) {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}