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
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v) {
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DSU dsu(n);

        unordered_map<string, int> mailToAccount;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if (mailToAccount.find(mail) == mailToAccount.end()) {
                    mailToAccount[mail] = i;
                } else {
                    dsu.unite(i, mailToAccount[mail]);
                }
            }
        }

        vector<vector<string>> mergedMails(n);

        for (auto &it : mailToAccount) {
            string mail = it.first;
            int parent = dsu.find(it.second);

            mergedMails[parent].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMails[i].empty())
                continue;

            sort(mergedMails[i].begin(), mergedMails[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (auto &mail : mergedMails[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};