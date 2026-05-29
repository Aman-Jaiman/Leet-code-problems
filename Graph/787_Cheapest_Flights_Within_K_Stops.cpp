#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // {stops, {node, cost}}

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int stops = cur.first;
            int node = cur.second.first;
            int cost = cur.second.second;

            if (stops > k) continue;

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int edgeCost = it.second;

                if (cost + edgeCost < dist[adjNode]) {
                    dist[adjNode] = cost + edgeCost;
                    q.push({stops + 1, {adjNode, cost + edgeCost}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 3, 500}
    };

    int src = 0;
    int dst = 3;
    int k = 1;

    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;

    return 0;
}