/*
LeetCode Problem 18. 4Sum

❓ Question:
Given an array nums of n integers, return all unique quadruplets [nums[a], nums[b], nums[c], nums[d]]
such that:
    - 0 <= a, b, c, d < n
    - a, b, c, and d are distinct
    - nums[a] + nums[b] + nums[c] + nums[d] == target

⚡ Notice:
- The solution set must not contain duplicate quadruplets.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans; // edge case

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicate j

                int p = j + 1, q = n - 1;
                while (p < q) {
                    long long sum = (long long)nums[i] + (long long)nums[j] +
                                    (long long)nums[p] + (long long)nums[q];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;

                        // skip duplicates
                        while (p < q && nums[p] == nums[p - 1]) p++;
                        while (p < q && nums[q] == nums[q + 1]) q--;
                    }
                    else if (sum < target) {
                        p++;
                    }
                    else {
                        q--;
                    }
                }
            }
        }
        return ans;
    }
};

// ---------- Driver code ----------
int main() {
    Solution sol;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    vector<vector<int>> res = sol.fourSum(nums, target);

    cout << "Quadruplets are:\n";
    for (auto &quad : res) {
        cout << "[ ";
        for (int x : quad) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
