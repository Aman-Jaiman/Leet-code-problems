/*
LeetCode Problem 15. 3Sum

❓ Question:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

⚡ Notice:
- The solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = []
Output: []

Example 3:
Input: nums = [0]
Output: []
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0) k--;
                else if (sum < 0) j++;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; 
                    k--;

                    // skip duplicate j
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    // skip duplicate k
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};


// ---------- Driver code ----------
int main() {
    Solution sol;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = sol.threeSum(nums);

    cout << "Triplets are:\n";
    for (auto &triplet : ans) {
        cout << "[ ";
        for (int x : triplet) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
