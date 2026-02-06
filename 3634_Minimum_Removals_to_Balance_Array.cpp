#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return 0;

        sort(nums.begin(), nums.end());

        int maxWindow = 1;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < n && (long long)nums[j] <= (long long)nums[i] * k) {
                maxWindow = max(maxWindow, j - i + 1);
                j++;
            }
        }
        return n - maxWindow;
    }
};
