#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;  // base case

        int sum = 0, ans = 0;

        for (int num : nums) {
            sum += num;

            if (mp.find(sum - goal) != mp.end()) {
                ans += mp[sum - goal];
            }

            mp[sum]++;
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << obj.numSubarraysWithSum(nums, goal) << endl;
    return 0;
}