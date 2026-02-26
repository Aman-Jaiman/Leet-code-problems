#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            // Compare mid with next element
            if (nums[mid] > nums[mid + 1]) {
                // Peak lies on left side (including mid)
                end = mid;
            } else {
                // Peak lies on right side
                st = mid + 1;
            }
        }

        return st;   // st == end, peak index
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 1};

    int peakIndex = sol.findPeakElement(nums);

    cout << "Peak Element Index: " << peakIndex << endl;
    cout << "Peak Element Value: " << nums[peakIndex] << endl;

    return 0;
}