/*
LeetCode 46. Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

This file provides a clean C++ solution using backtracking (in-place swapping).

Time complexity: O(n * n!) — there are n! permutations and we copy each of length n.
Space complexity: O(n) recursion depth (not counting output storage).

Usage:
  - Provide input as: first an integer n, then n integers (space-separated).
  - If no input is provided, the program runs with the default example {1,2,3}.

Example:
  Input:
    3 1 2 3
  Output:
    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 2 1
    3 1 2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    // Backtracking using in-place swapping
    void backtrack(vector<int>& nums, int idx){
        if (idx == (int)nums.size()){
            res.push_back(nums);
            return;
        }
        for (int i = idx; i < (int)nums.size(); ++i){
            swap(nums[idx], nums[i]);            // choose
            backtrack(nums, idx + 1);           // explore
            swap(nums[idx], nums[i]);            // undo (backtrack)
        }
    }

    vector<vector<int>> permute(vector<int>& nums){
        res.clear();
        backtrack(nums, 0);
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums;
    int n;
    if (!(cin >> n)){
        // no input given: use default example
        nums = {1, 2, 3};
        n = 3;
    } else {
        nums.resize(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];
    }

    Solution sol;
    auto ans = sol.permute(nums);

    for (auto &p : ans){
        for (size_t i = 0; i < p.size(); ++i){
            if (i) cout << ' ';
            cout << p[i];
        }
        cout << '\n';
    }

    return 0;
}
