#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        vector<int>ans;
        int n=arr.size();
        if(n==0) return ans;
        ans.push_back(arr[n-1]);
        int j=0;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=ans[j]){
                ans.push_back(arr[i]);
                j++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};