#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Target found
            if (nums[mid] == target) return true;

            // If duplicates prevent decision
            if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
                st++;
                end--;
                continue;
            }

            // Left half sorted
            if (nums[st] <= nums[mid]) {
                if (target >= nums[st] && target < nums[mid])
                    end = mid - 1;
                else
                    st = mid + 1;
            }
            // Right half sorted
            else {
                if (target > nums[mid] && target <= nums[end])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }
};

// Optional main for local testing
int main() {
    Solution sol;
    vector<int> nums = {1,1,1,3,1};
    int target = 3;

    if (sol.search(nums, target))
        cout << "Target Found\n";
    else
        cout << "Target Not Found\n";

    return 0;
}