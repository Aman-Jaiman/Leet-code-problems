/*
LeetCode Problem 26: Remove Duplicates from Sorted Array

Problem:
Given a sorted array nums, remove the duplicates in-place such that each element 
appears only once and returns the new length.

Do not allocate extra space for another array; you must do this by modifying 
the input array in-place with O(1) extra memory.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2]

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4]

Constraints:
1 <= nums.length <= 3 * 10^4
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; // slow pointer - last unique element index

        for (int j = 1; j < nums.size(); j++) { // fast pointer
            if (nums[j] != nums[i]) {          // new unique element found
                i++;
                nums[i] = nums[j];             // move to front
            }
        }

        return i + 1; // length of unique elements
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int length = sol.removeDuplicates(nums);

    cout << "Length of unique elements: " << length << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < length; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
