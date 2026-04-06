#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;

    void helper(int k, int n, int i) {
        // valid combination
        if (vec.size() == k && n == 0) {
            ans.push_back(vec);
            return;
        }

        // stop conditions
        if (i > 9 || n < 0 || vec.size() > k) {
            return;
        }

        // pick current number
        vec.push_back(i);
        helper(k, n - i, i + 1);
        vec.pop_back();

        // skip current number
        helper(k, n, i + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        helper(k, n, 1);
        return ans;
    }
};

int main() {
    Solution obj;
    int k = 3, n = 7;

    vector<vector<int>> result = obj.combinationSum3(k, n);

    for (auto &v : result) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}