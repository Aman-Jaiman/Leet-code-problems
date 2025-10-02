/*
 * 78. Subsets
 * 
 * Given an integer array nums of unique elements, return all possible subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets.
 * You may return the answer in any order.
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * Constraints:
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;   // to store all subsets
        vector<int> current;          // current subset
        backtrack(nums, 0, current, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        // Add current subset to result
        result.push_back(current);

        // Explore further choices
        for(int i = index; i < nums.size(); i++) {
            // Include nums[i]
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            // Backtrack (remove last added element)
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3};

    vector<vector<int>> ans = sol.subsets(nums);

    cout << "All subsets are: \n";
    for(auto subset : ans) {
        cout << "[ ";
        for(int x : subset) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
