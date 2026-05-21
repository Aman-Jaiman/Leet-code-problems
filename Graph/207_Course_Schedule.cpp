#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build graph
        for (auto it : prerequisites) {

            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        // Kahn's Algorithm
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for (auto neigh : adj[node]) {

                indegree[neigh]--;

                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return count == n;
    }
};

int main() {

    Solution obj;

    int numCourses = 2;

    vector<vector<int>> prerequisites = {
        {1, 0}
    };

    if (obj.canFinish(numCourses, prerequisites)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}