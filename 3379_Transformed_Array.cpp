#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = 0;
            } else {
                int newIndex = (i + nums[i]) % n;
                if (newIndex < 0)
                    newIndex += n;   // handle negative wrap

                result[i] = nums[newIndex];
            }
        }
        return result;
    }
};
