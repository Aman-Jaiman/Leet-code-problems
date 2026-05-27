#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string findOrder(vector<string> &words) {

        vector<unordered_set<int>> adj(26);

        vector<int> ind(26, 0);
        vector<int> present(26, 0);

        // Mark present characters
        for (auto word : words) {

            for (char ch : word) {
                present[ch - 'a'] = 1;
            }
        }

        // Build graph
        for (int i = 1; i < words.size(); i++) {

            string s1 = words[i - 1];
            string s2 = words[i];

            int len = min(s1.size(), s2.size());

            // Invalid case
            if (s1.size() > s2.size() &&
                s1.substr(0, len) == s2) {

                return "";
            }

            for (int j = 0; j < len; j++) {

                if (s1[j] != s2[j]) {

                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';

                    // Avoid duplicate edges
                    if (adj[u].find(v) == adj[u].end()) {

                        adj[u].insert(v);

                        ind[v]++;
                    }

                    break;
                }
            }
        }

        int count = 0;

        queue<int> q;

        // Push indegree 0 characters
        for (int i = 0; i < 26; i++) {

            if (present[i]) count++;

            if (present[i] && ind[i] == 0) {
                q.push(i);
            }
        }

        string ans;

        // Kahn's Algorithm
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for (auto neigh : adj[node]) {

                ind[neigh]--;

                if (ind[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        // Cycle detection
        if (ans.size() != count) {
            return "";
        }

        return ans;
    }
};

int main() {

    vector<string> words = {
        "baa",
        "abcd",
        "abca",
        "cab",
        "cad"
    };

    Solution obj;

    string ans = obj.findOrder(words);

    if (ans == "") {
        cout << "Invalid Dictionary Order" << endl;
    }
    else {
        cout << "Alien Dictionary Order: " << ans << endl;
    }

    return 0;
}