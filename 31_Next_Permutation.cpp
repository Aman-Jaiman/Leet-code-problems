/*
LeetCode 31. Next Permutation
--------------------------------
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

- The next permutation of an array of integers is the next lexicographically greater permutation of its integer sequence.
- If such arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
- The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Step 1: Find pivot (rightmost index where nums[i] < nums[i+1])
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot found, nums is the highest permutation
        // Just reverse it to get the lowest
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find rightmost element greater than nums[pivot]
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse the suffix after pivot
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

// Helper function to print vector
void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << (i + 1 == v.size() ? "" : " ");
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example test case
    vector<int> nums = {1, 2, 3};
    cout << "Original: ";
    printVector(nums);

    sol.nextPermutation(nums);

    cout << "Next permutation: ";
    printVector(nums);

    return 0;
}
