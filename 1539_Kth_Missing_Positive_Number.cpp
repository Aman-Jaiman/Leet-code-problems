#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int st=0;
        int end=nums.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            int miss=nums[mid]-(mid+1);
            if(miss<k){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }

        return st+k;
    }
};