/*
 * 90. Subsets II
 * 
 * Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 * 
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[2],[1,2],[2,2],[1,2,2]]
 * 
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * Constraints:
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end()); // sort to handle duplicates
        backtrack(nums, 0, current, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        
        for(int i = index; i < nums.size(); i++) {
            // Skip duplicate numbers at the same recursion level
            if(i > index && nums[i] == nums[i-1]) continue;
            
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,2};
    
    vector<vector<int>> ans = sol.subsetsWithDup(nums);
    
    cout << "All unique subsets are:\n";
    for(auto subset : ans) {
        cout << "[ ";
        for(int x : subset) cout << x << " ";
        cout << "]\n";
    }
    
    return 0;
}
