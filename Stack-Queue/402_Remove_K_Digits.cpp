#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(int i = 0; i < num.size(); i++) {

            while(!st.empty() && k > 0 && num[i] < st.top()) {
                st.pop();
                k--;
            }

            if(st.empty() && num[i] == '0') 
                continue;

            st.push(num[i]);
        }

        // remove remaining digits if k still > 0
        while(!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        if(ans == "") return "0";

        return ans;
    }
};

int main() {
    Solution obj;

    string num = "1432219";
    int k = 3;

    cout << obj.removeKdigits(num, k) << endl;

    return 0;
}