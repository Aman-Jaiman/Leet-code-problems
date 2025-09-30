/*
File: 560_Subarray_Sum_Equals_K.cpp
LeetCode Problem 560. Subarray Sum Equals K

❓ Question:
Given an array of integers nums and an integer k, return the total number of subarrays
whose sum equals to k.

⚡ Note:
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Explanation: Subarrays [1,1] (index 0..1) and [1,1] (index 1..2) both sum to 2.

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
Explanation: Subarrays [1,2] (index 0..1) and [3] (index 2) sum to 3.

Constraints:
- 1 <= nums.length <= 2 * 10^4
- -1000 <= nums[i] <= 1000
- -10^7 <= k <= 10^7
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> prefixMap;  // prefixSum -> frequency
        int prefixSum = 0;

        for (int j = 0; j < n; j++) {
            prefixSum += nums[j];  // running prefix sum

            // Case 1: subarray from 0..j itself equals k
            if (prefixSum == k) count++;

            // Case 2: check if prefixSum[j] - k exists
            int val = prefixSum - k;
            if (prefixMap.find(val) != prefixMap.end()) {
                count += prefixMap[val];
            }

            // Update frequency of prefixSum
            prefixMap[prefixSum]++;
        }

        return count;
    }
};

// ---------- Driver Code ----------
int main() {
    Solution sol;

    vector<int> nums = {1,2,3};
    int k = 3;

    cout << "Number of subarrays with sum = " << k << " : ";
    cout << sol.subarraySum(nums, k) << endl;

    return 0;
}
