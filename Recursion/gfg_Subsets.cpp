#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;

    void helper(vector<int>& arr, int i) {
        if (i == arr.size()) {
            ans.push_back(vec);
            return;
        }

        // Pick the element
        vec.push_back(arr[i]);
        helper(arr, i + 1);

        // Not pick the element
        vec.pop_back();
        helper(arr, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        helper(arr, 0);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> result = obj.subsets(arr);

    for (auto &subset : result) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}