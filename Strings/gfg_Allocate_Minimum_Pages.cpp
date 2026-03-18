#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool maxPage(int k, vector<int>& arr, int mid){
        int students = 1;
        int sum = 0;

        for(int it : arr){
            if(it > mid) return false;

            if(sum + it <= mid){
                sum += it;
            } else {
                students++;
                sum = it;
            }

            if(students > k) return false;
        }

        return true;
    }

    int findPages(vector<int> &arr, int k) {
        if(k > arr.size()) return -1;

        int st = *max_element(arr.begin(), arr.end());
        int end = 0;

        for(int it : arr){
            end += it;
        }

        int ans = end;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(maxPage(k, arr, mid)){
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};