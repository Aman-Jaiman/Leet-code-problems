#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long solveMax(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        long long ans = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                
                int idx = st.top();
                st.pop();

                int left = st.empty() ? idx + 1 : idx - st.top();
                int right = i - idx;

                ans += (long long)nums[idx] * left * right;
            }
            st.push(i);
        }

        return ans;
    }

    long long solveMin(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        long long ans = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                
                int idx = st.top();
                st.pop();

                int left = st.empty() ? idx + 1 : idx - st.top();
                int right = i - idx;

                ans += (long long)nums[idx] * left * right;
            }
            st.push(i);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return solveMax(nums) - solveMin(nums);
    }
};