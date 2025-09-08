// LeetCode 75 - Sort Colors Problem
// Question:
// Given an array nums with n objects colored red, white, or blue, sort them in-place
// so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// Use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// Example:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0 = 0, c1 = 0, c2 = 0;
        // Count 0s, 1s, and 2s
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) c0++;
            else if(nums[i] == 1) c1++;
            else c2++;
        }
        int index = 0;
        // Fill 0s
        for(int i = 0; i < c0; i++) nums[index++] = 0;
        // Fill 1s
        for(int i = 0; i < c1; i++) nums[index++] = 1;
        // Fill 2s
        for(int i = 0; i < c2; i++) nums[index++] = 2;
    }
};

int main() {
    vector<int> nums = {2,0,2,1,1,0};
    Solution sol;
    sol.sortColors(nums);
    for(int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}
