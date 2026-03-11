#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;  // position for next non-zero

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    Solution obj;
    obj.moveZeroes(nums);

    for (int x : nums)
        cout << x << " ";

    return 0;
}
