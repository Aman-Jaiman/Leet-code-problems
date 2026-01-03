#include <bits/stdc++.h>
using namespace std;

/*
 Problem: Combination Sum

 Given an array of distinct integers arr[] and a target integer,
 return all unique combinations where the chosen numbers sum to target.

 A number may be used unlimited times.
*/

class Solution {
public:
    void getAllCombination(
        vector<int>& arr,
        int idx,
        int target,
        vector<vector<int>>& ans,
        vector<int>& combin
    ) {
        // ✅ if target achieved
        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        // ❌ out of bounds or target exceeded
        if (idx == arr.size() || target < 0) {
            return;
        }

        // 1️⃣ pick the current element (can reuse same index)
        combin.push_back(arr[idx]);
        getAllCombination(arr, idx, target - arr[idx], ans, combin);
        combin.pop_back(); // backtracking

        // 2️⃣ skip the current element
        getAllCombination(arr, idx + 1, target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        getAllCombination(arr, 0, target, ans, combin);
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(arr, target);

    // Output
    cout << "Combinations that sum to " << target << ":\n";
    for (auto &v : result) {
        cout << "[ ";
        for (int x : v) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
