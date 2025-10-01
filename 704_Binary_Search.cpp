/*
File: 704_Binary_Search.cpp
LeetCode Problem 704. Binary Search

❓ Question:
Given an array of integers nums which is sorted in ascending order, 
and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

⚡ Note:
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4.

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1.

Constraints:
- 1 <= nums.length <= 10^4
- -10^4 < nums[i], target < 10^4
- All the integers in nums are unique.
- nums is sorted in ascending order.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // to avoid overflow

            if (nums[mid] == target) 
                return mid;   // target found
            else if (nums[mid] < target) 
                left = mid + 1;  // search in right half
            else 
                right = mid - 1; // search in left half
        }

        return -1; // target not found
    }
};

// ---------- Driver Code ----------
int main() {
    Solution sol;

    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;

    cout << "Index of target " << target << " : ";
    cout << sol.search(nums, target) << endl;

    return 0;
}
