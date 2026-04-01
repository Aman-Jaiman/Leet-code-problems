#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;

    void CombSum(vector<int>& candidates, int target, int sum, int i){

        if(sum == target){
            ans.push_back(vec);
            return;
        }

        if(i >= candidates.size() || sum > target){
            return;
        }

        // take element
        vec.push_back(candidates[i]);
        CombSum(candidates, target, sum + candidates[i], i);

        // backtrack
        vec.pop_back();

        // skip element
        CombSum(candidates, target, sum, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        CombSum(candidates, target, 0, 0);

        return ans;
    }
};