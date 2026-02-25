#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            // Ensure mid is even
            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1]) {
                // Single element is on the right side
                st = mid + 2;
            } else {
                // Single element is on the left side (including mid)
                end = mid;
            }
        }

        return nums[st];
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    cout << "Single Element: " << sol.singleNonDuplicate(nums) << endl;

    return 0;
}