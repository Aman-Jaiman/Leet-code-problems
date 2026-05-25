#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;

        vector<vector<int>> adj(n);
        vector<int> ans;
        vector<int> ind(n, 0);

        // Build graph
        for (auto it : prerequisites) {
            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
            ind[a]++;
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        // Kahn's Algorithm
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);
            count++;

            for (auto neigh : adj[node]) {

                ind[neigh]--;

                if (ind[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        // Cycle exists
        if (count != n) return {};

        return ans;
    }
};

int main() {

    Solution obj;

    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };

    vector<int> ans = obj.findOrder(numCourses, prerequisites);

    if (ans.empty()) {
        cout << "No valid ordering possible\n";
    }
    else {
        for (auto x : ans) {
            cout << x << " ";
        }
    }

    return 0;
}