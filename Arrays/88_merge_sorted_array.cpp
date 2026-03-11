/*
LeetCode 88. Merge Sorted Array
--------------------------------
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums2 into nums1 as one sorted array.
The final sorted array should not be returned by the function, but instead 
be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements 
denote the elements that should be merged, and the last n elements are set to 0 
and should be ignored. nums2 has a length of n.

Example:
Input: 
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: 
[1,2,2,3,5,6]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        int i = m - 1, j = n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[index--] = nums1[i--];
            } else {
                nums1[index--] = nums2[j--];
            }
        }

        // If any elements are left in nums2, copy them
        while (j >= 0) {
            nums1[index--] = nums2[j--];
        }
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
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;

    cout << "Before merge: ";
    printVector(nums1);

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    cout << "After merge:  ";
    printVector(nums1);

    return 0;
}
