#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int sub = 0;

        for(int i = 0; i < nums.size(); i++){
            sub += nums[i];
            sum = max(sum, sub);

            if(sub < 0)
                sub = 0;
        }

        return sum;
    }
};