#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans=0;
        for(int i=1; i<prices.size(); i++){
            ans = max(ans, prices[i] - mini);

            // Remembring is Part of dp
            mini = min(mini, prices[i]);
        }
        return ans;
    }
};