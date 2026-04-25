#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, zeros = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;

            // shrink until valid (at most k zeros)
            while (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << s.longestOnes(nums, k) << endl; // Output: 6
}