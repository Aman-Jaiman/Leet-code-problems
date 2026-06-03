#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        int V = dist.size();

        // Convert -1 to INF
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == -1)
                    dist[i][j] = 1e8;
            }
        }

        // Floyd-Warshall Algorithm
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != 1e8 && dist[k][j] != 1e8) {
                        dist[i][j] = min(dist[i][j],
                                         dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Convert INF back to -1
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == 1e8)
                    dist[i][j] = -1;
            }
        }
    }
};

int main() {
    int V;
    cin >> V;

    vector<vector<int>> dist(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> dist[i][j];
        }
    }

    Solution obj;
    obj.floydWarshall(dist);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}