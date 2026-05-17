// solution.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        // Build indegree and outdegree
        for(int i = 0; i < trust.size(); i++) {

            int a = trust[i][0];
            int b = trust[i][1];

            outdegree[a]++;
            indegree[b]++;
        }

        // Find judge
        for(int i = 1; i <= n; i++) {

            if(indegree[i] == n - 1 &&
               outdegree[i] == 0) {

                return i;
            }
        }

        return -1;
    }
};

int main() {

    Solution obj;

    int n = 3;

    vector<vector<int>> trust = {
        {1,3},
        {2,3}
    };

    cout << obj.findJudge(n, trust);

    return 0;
}