#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = arr[st.top()];

            st.push(i);
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    
    Solution obj;
    vector<int> res = obj.nextSmallerEle(arr);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}