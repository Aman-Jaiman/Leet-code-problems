#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> arr;

        for (int x : nums) {

            if (arr.empty() || x > arr.back()) {
                arr.push_back(x);
            } else {
                int lb = 0;
                int ub = arr.size() - 1;

                while (lb < ub) {
                    int mid = lb + (ub - lb) / 2;

                    if (arr[mid] >= x)
                        ub = mid;
                    else
                        lb = mid + 1;
                }

                arr[lb] = x;   // ✅ Replace after binary search finishes
            }
        }

        return arr.size();
    }
};

