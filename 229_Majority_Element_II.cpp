#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int ans1 = 0, ans2 = 1;   // initialize differently
        int n = nums.size();

        if(n == 0) return {};

        // Step 1: Find potential candidates
        for(int i = 0; i < n; i++) {
            if(nums[i] == ans1) {
                count1++;
            }
            else if(nums[i] == ans2) {
                count2++;
            }
            else if(count1 == 0) {
                ans1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0) {
                ans2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify candidates
        count1 = count2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == ans1) count1++;
            else if(nums[i] == ans2) count2++;
        }

        vector<int> ans;

        if(count1 > n/3) ans.push_back(ans1);
        if(count2 > n/3) ans.push_back(ans2);

        return ans;
    }
};
