/*
LeetCode Problem 11: Container With Most Water

You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the i-th line 
are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, 
such that the container contains the most water.

Return the maximum amount of water a container can store.

Constraints:
- n >= 2
- 1 <= height[i] <= 10^4
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            maxWater = max(maxWater, width * h);

            // Move pointer of smaller height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Max water container: " << sol.maxArea(height) << endl;
    return 0;
}
