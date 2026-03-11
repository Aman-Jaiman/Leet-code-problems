// File: 27. Remove Element.cpp
//
// Problem Statement:
// Given an integer array nums and an integer val,
// remove all occurrences of val in nums "in-place".
// The order of elements may change.
// Return the number of elements left (not equal to val).
//
// After removal, the first k elements of the array
// must contain the valid elements,
// and k should be returned.
//
// Example:
// Input: nums = [3,2,2,3], val = 3
// Output: 2
// Modified array: [2,2,_,_]
//
// Example:
// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5
// Modified array: [0,1,3,0,4,_,_,_]
//
// Constraints:
// - 0 <= nums.length <= 100
// - 0 <= nums[i] <= 50
// - 0 <= val <= 100

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i; // i = number of elements not equal to val
    }
};

// -------- Helper functions for local testing --------

void printVector(const vector<int>& nums, int k) {
    cout << "[ ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << "]\n";
}

int main() {
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    Solution sol;
    int k = sol.removeElement(nums, val);

    cout << "Output: " << k << endl;
    cout << "Modified array: ";
    printVector(nums, k);

    return 0;
}
