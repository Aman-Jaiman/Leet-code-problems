#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;

    void helper(vector<int>& nums, int i){
        if(i == nums.size()){
            ans.push_back(vec);
            return;
        }

        // Pick current element
        vec.push_back(nums[i]);
        helper(nums, i + 1);
        vec.pop_back();

        // Skip duplicates for "not pick"
        while(i + 1 < nums.size() && nums[i] == nums[i + 1]) 
            i++;

        helper(nums, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0);
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = obj.subsetsWithDup(nums);

    for(auto &subset : result){
        cout << "[ ";
        for(int x : subset){
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}