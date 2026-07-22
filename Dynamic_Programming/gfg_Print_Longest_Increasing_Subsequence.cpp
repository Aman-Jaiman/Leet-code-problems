#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> dp(n,1), hash(n);
        
        int maxi = 1;
        int lastInd = 0;
        
        for(int i=0;i<n; i++){
            hash[i] =i;
            for(int prev = 0; prev<i; prev++){
                if(arr[prev] < arr[i] && dp[prev] + 1 > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            
            if(dp[i] > maxi){
                maxi =dp[i];
                lastInd = i;
            }
            
        }
        
        vector<int> ans;
        while(hash[lastInd] != lastInd){
            ans.push_back(arr[lastInd]);
            lastInd = hash[lastInd];
        }
        
        ans.push_back(arr[lastInd]);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};