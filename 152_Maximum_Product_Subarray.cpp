#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        long long maxProd = nums[0];
        long long minProd = nums[0];
        long long result = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            // If current number is negative, swap
            if(nums[i] < 0)
                swap(maxProd, minProd);

            // Update max and min product ending here
            maxProd = max((long long)nums[i], maxProd * nums[i]);
            minProd = min((long long)nums[i], minProd * nums[i]);

            // Update global result
            result = max(result, maxProd);
        }

        return (int)result;
    }
};
