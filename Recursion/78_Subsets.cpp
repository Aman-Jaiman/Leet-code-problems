#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>vec;
    void helper(vector<int>&nums,int i){
        if(i==nums.size()){
            ans.push_back(vec);
            return ;
        }

        vec.push_back(nums[i]);
        helper(nums,i+1);
        vec.pop_back();

        helper(nums,i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums,0);
        return ans;
    }
};