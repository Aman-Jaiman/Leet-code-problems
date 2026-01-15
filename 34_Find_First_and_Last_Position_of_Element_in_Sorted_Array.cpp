#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstPos(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                ans = mid;
                end = mid - 1;   // left side
            } else if (nums[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    int lastPos(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                ans = mid;
                st = mid + 1;   // right side
            } else if (nums[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        int first = firstPos(nums, target);
        if (first == -1) return {-1, -1};

        int last = lastPos(nums, target);
        return {first, last};
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> ans = s.searchRange(nums, target);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
