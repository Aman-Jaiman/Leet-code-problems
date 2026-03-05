#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        int st = *max_element(nums.begin(), nums.end());
        int end = 0;

        for (int n : nums) {
            end += n;
        }

        int ans = end;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            int subarrays = 1;
            int currSum = 0;

            for (int n : nums) {
                if (currSum + n > mid) {
                    subarrays++;
                    currSum = n;
                } else {
                    currSum += n;
                }
            }

            if (subarrays > k) {
                st = mid + 1;
            } else {
                ans = mid;
                end = mid - 1;
            }
        }

        return ans;
    }
};