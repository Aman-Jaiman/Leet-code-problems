#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] > nums[end]) {
                // Minimum is in right half
                st = mid + 1;
            } 
            else {
                // Minimum is in left half including mid
                end = mid;
            }
        }

        return nums[st];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};

    cout << "Minimum element: " << sol.findMin(nums) << endl;

    return 0;
}