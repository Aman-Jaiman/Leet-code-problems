#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);

        int lastInd = 0;
        int maxi=0;

        sort(nums.begin(), nums.end());
        for(int i =0; i<n ; i++){
            hash[i] =i;

            for(int j= i-1; j>=0; j++){
                if(nums[i] % nums[j] ==0 ){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] +1;
                        hash[i] = j;
                        break;
                    }
                    
                }
            }
            if(maxi < dp[i]){
                maxi =dp[i];
                lastInd =i;
            }
        }

        vector<int>ans;
        while(hash[lastInd] != lastInd){
            ans.push_back(nums[lastInd]);
            lastInd = hash[lastInd];
        }
        ans.push_back(nums[lastInd]);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};