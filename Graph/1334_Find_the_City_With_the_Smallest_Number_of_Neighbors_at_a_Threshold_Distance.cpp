#include <bits/stdc++.h>
using namespace std;

// Using Floyd-Warshall Algo : O(n^3)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for(int i = 0; i < n; i++)
            dist[i][i] = 0;

        for(auto &e : edges){
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }

        int city = -1;
        int reachable = n;

        for(int i = 0; i < n; i++){
            int count = 0;

            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold)
                    count++;
            }

            if(count <= reachable){
                reachable = count;
                city = i;
            }
        }

        return city;
    }
};

// Using Dijkstra Dijkstra once: O(E log V)
// Run for all cities: O(V * E log V)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int city = -1;
        int minReach = n;

        for (int src = 0; src < n; src++) {

            vector<int> dist(n, 1e9);
            dist[src] = 0;

            priority_queue<
                pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>>
            > pq;

            pq.push({0, src});

            while (!pq.empty()) {

                auto [d, node] = pq.top();
                pq.pop();

                if (d > dist[node]) continue;

                for (auto &[next, wt] : adj[node]) {

                    if (dist[node] + wt < dist[next]) {
                        dist[next] = dist[node] + wt;
                        pq.push({dist[next], next});
                    }
                }
            }

            int count = 0;

            for (int i = 0; i < n; i++) {
                if (dist[i] <= distanceThreshold)
                    count++;
            }

            if (count <= minReach) {
                minReach = count;
                city = src;
            }
        }

        return city;
    }
};

