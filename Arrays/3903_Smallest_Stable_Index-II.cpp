#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minRight(n);

        minRight[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--) {
            minRight[i] = min(nums[i], minRight[i+1]);
        }

        int maxLeft = nums[0];

        for(int i = 0; i < n; i++) {
            maxLeft = max(maxLeft, nums[i]);

            if(maxLeft - minRight[i] <= k)
                return i;
        }

        return -1;
    }
};