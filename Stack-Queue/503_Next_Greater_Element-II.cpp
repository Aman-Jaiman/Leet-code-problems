#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = 2*n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            if(i < n) {
                if(!st.empty()) {
                    ans[i] = st.top();
                }
            }

            st.push(nums[i % n]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 1};
    vector<int> result = obj.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}