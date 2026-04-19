#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstStableIndex(vector<int>& arr, int k) {
        int n =arr.size();
        int max=arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]>max){
                max=arr[i];
            }
            int min=arr[i];
            for(int j=i;j<n;j++){
                if(arr[j]<min){
                    min=arr[j];
                }
            }
            if(max-min<=k) return i;
        }
        return -1;
    }
};