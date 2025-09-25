/*
287. Find the Duplicate Number

Problem:
You are given an array of integers nums containing n + 1 integers 
where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array and 
using only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Constraints:
- 1 <= n <= 10^5
- nums.length == n + 1
- 1 <= nums[i] <= n
- All the integers in nums appear only once except for exactly one integer which appears two or more times.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Floyd's Tortoise and Hare Algorithm (Cycle Detection)

        // Step 1: Initialize slow and fast pointer
        int slow = nums[0];
        int fast = nums[0];

        // Step 2: First phase → Find intersection point inside the cycle
        // slow moves 1 step, fast moves 2 steps
        do {
            slow = nums[slow];         // move by 1 step
            fast = nums[nums[fast]];   // move by 2 steps
        } while (slow != fast);

        // Step 3: Second phase → Find entrance to cycle (duplicate number)
        slow = nums[0];  // reset slow to start
        while (slow != fast) {
            slow = nums[slow]; // move 1 step
            fast = nums[fast]; // move 1 step
        }

        // Step 4: The meeting point is the duplicate number
        return slow;
    }
};

// ---------- Driver Code (for testing locally) ----------
int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 4, 2, 2};
    cout << "Duplicate in nums1: " << sol.findDuplicate(nums1) << endl; // Output: 2

    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << "Duplicate in nums2: " << sol.findDuplicate(nums2) << endl; // Output: 3

    return 0;
}
