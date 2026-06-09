#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    void unit(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DSU dsu(n * n);

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        // Connect all existing islands
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 0) continue;

                int node = row * n + col;

                for (int i = 0; i < 4; i++) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if (nrow >= 0 && nrow < n &&
                        ncol >= 0 && ncol < n &&
                        grid[nrow][ncol] == 1) {

                        int adjNode = nrow * n + ncol;
                        dsu.unit(node, adjNode);
                    }
                }
            }
        }

        int ans = 0;

        // Try converting each 0 to 1
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1) continue;

                unordered_set<int> st;

                for (int i = 0; i < 4; i++) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if (nrow >= 0 && nrow < n &&
                        ncol >= 0 && ncol < n &&
                        grid[nrow][ncol] == 1) {

                        st.insert(dsu.find(nrow * n + ncol));
                    }
                }

                int sizeTotal = 1;

                for (auto parent : st) {
                    sizeTotal += dsu.size[parent];
                }

                ans = max(ans, sizeTotal);
            }
        }

        // If grid already contains all 1's
        for (int i = 0; i < n * n; i++) {
            ans = max(ans, dsu.size[dsu.find(i)]);
        }

        return ans;
    }
};