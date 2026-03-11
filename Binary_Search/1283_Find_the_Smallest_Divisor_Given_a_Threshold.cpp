#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int st = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = end;

        while(st <= end){
            int mid = st + (end - st) / 2;
            long long count = 0;

            // Calculate sum of ceil(nums[i] / mid)
            for(int i = 0; i < nums.size(); i++){
                count += (nums[i] + mid - 1) / mid;
            }

            if(count <= threshold){
                ans = mid;        // possible answer
                end = mid - 1;    // try smaller divisor
            }
            else{
                st = mid + 1;     // need bigger divisor
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << "Smallest Divisor: "
         << obj.smallestDivisor(nums, threshold) << endl;

    return 0;
}