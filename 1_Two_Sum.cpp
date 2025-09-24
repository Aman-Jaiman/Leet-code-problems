// 1_two_sum.cpp
// LeetCode Problem 1: Two Sum

/*
Problem Statement:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
- Each input has exactly one solution.
- You may not use the same element twice.
- You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
*/

#include <bits/stdc++.h>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
// Brute-force solution    
    // int n = nums.size();
    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         if (nums[i] + nums[j] == target) {
    //             return {i, j};  // return indices
    //         }
    //     }
    // }
    // return {}; // will never reach here if solution exists

    unordered_map<int,int> mp;  // value -> index
        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            if(mp.find(diff)!=mp.end()){
                return {mp[diff], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);
    cout << "Indices: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}
