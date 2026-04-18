#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && st.top() > 0 && asteroids[i] < 0) {

                if(st.top() + asteroids[i] == 0) {
                    st.pop();
                }
                else if(st.top() < abs(asteroids[i])) {
                    st.pop();
                    continue;
                }

                asteroids[i] = 0;
                break;
            }

            if(asteroids[i] != 0)
                st.push(asteroids[i]);
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};