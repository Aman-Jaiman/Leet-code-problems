#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;

        for (int i = 0; i <= n; i++) {

            while (!st.empty() && (i == n || heights[st.top()] > heights[i])) {

                int h = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                ans = max(ans, h * width);
            }

            st.push(i);
        }

        return ans;
    }
};

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    Solution obj;
    cout << obj.largestRectangleArea(heights) << endl;

    return 0;
}