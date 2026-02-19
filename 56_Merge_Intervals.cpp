#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.size() <= 1)
            return intervals;

        // Step 1: Sort intervals
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        // Step 2: Traverse and merge
        for(int i = 1; i < intervals.size(); i++) {

            // If overlapping
            if(intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
