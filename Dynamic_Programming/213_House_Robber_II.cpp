#include<bits/stdc++.h>
using namespace std;

// Optimal Approch TC: O(n) and SC: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int prev1=nums[0];
        int prev2=max(nums[0],nums[1]);
        int p1=nums[1];
        int p2=max(nums[1],nums[2]);
        for(int i=2;i<n-1;i++){
            int curr=max(prev1+nums[i], prev2);
            prev1=prev2;
            prev2=curr;
            int c=max(p1+nums[i+1], p2);
            p1=p2;
            p2=c;
        }
        
        return max(prev2,p2);
    }
};

