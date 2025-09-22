/*
4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.0
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.5
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
- nums1.length == m
- nums2.length == n
- 0 <= m, n <= 1000
- 1 <= m + n <= 2000
- -10^6 <= nums1[i], nums2[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> merged;
        int i = 0, j = 0;

        // Merge two sorted arrays
        while(i < n1 && j < n2) {
            if(nums1[i] < nums2[j]) {
                merged.push_back(nums1[i++]);
            } else {
                merged.push_back(nums2[j++]);
            }
        }

        while(i < n1) merged.push_back(nums1[i++]);
        while(j < n2) merged.push_back(nums2[j++]);

        int total = n1 + n2;

        // Find median
        if(total % 2 == 0) {
            return ( (double)merged[total/2] + (double)merged[total/2 - 1] ) / 2.0;
        } else {
            return (double)merged[total/2];
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Median: " << sol.findMedianSortedArrays(nums3, nums4) << endl;

    vector<int> nums5 = {0, 0};
    vector<int> nums6 = {0, 0};
    cout << "Median: " << sol.findMedianSortedArrays(nums5, nums6) << endl;

    return 0;
}
