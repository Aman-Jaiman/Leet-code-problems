#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<vector<int>> ans;
    vector<int> vec;

    void helper(vector<int>& candidates, int target, int sum, int start){

        if(sum == target){
            ans.push_back(vec);
            return;
        }

        for(int i = start; i < candidates.size(); i++){

            if(i > start && candidates[i] == candidates[i-1]) continue;

            if(sum + candidates[i] > target) break;

            vec.push_back(candidates[i]);

            helper(candidates, target, sum + candidates[i], i + 1);

            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        helper(candidates, target, 0, 0);

        return ans;
    }
};