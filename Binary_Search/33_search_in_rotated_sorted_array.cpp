/*
LeetCode Problem 33: Search in Rotated Sorted Array

📌 Problem Statement:
You are given an integer array nums sorted in ascending order (with distinct values),
and an integer target.

But the array may have been rotated at some pivot index k (1 <= k < nums.length),
such that the resulting array is:
    nums = [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]

For example:
    [0,1,2,4,5,6,7] rotated at index 3 becomes [4,5,6,7,0,1,2].

👉 Your task:
Given the rotated sorted array nums and an integer target, return the index of target
if it is in nums, or -1 if it is not in nums.

⚡ Constraints:
- 1 <= nums.length <= 5000
- -10^4 <= nums[i] <= 10^4
- All values of nums are unique.
- nums is guaranteed to be rotated at some pivot.
- -10^4 <= target <= 10^4

⏱️ Complexity Requirement:
Your algorithm must run in O(log n) time.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] == target) {
                return m;
            }

            // Left half is sorted
            if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;  // target not found
    }
};

// 🔹 Driver code for testing
int main() {
    Solution obj;

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    int index = obj.search(nums, target);

    cout << "Target " << target << " found at index: " << index << endl;

    return 0;
}
