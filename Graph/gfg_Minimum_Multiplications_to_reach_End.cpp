#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {
        vector<int> vis(1000, 0);

        queue<pair<int, int>> q;
        q.push({start, 0});
        vis[start] = 1;

        while (!q.empty()) {
            auto [node, steps] = q.front();
            q.pop();

            if (node == end) {
                return steps;
            }

            for (int x : arr) {
                int next = (node * x) % 1000;

                if (!vis[next]) {
                    vis[next] = 1;
                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};