// Question:
// Given two integer sequences pushed and popped with distinct values, 
// return true if and only if this could have been the result of a 
// sequence of stack operations.
//
// Example 1:
// Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
// Output: true
//
// Example 2:
// Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
// Output: false

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0; // pointer for popped sequence

        for (int x : pushed) {
            st.push(x);
            // pop while stack top matches the popped sequence
            while (!st.empty() && j < popped.size() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        // valid if we popped all elements
        return j == popped.size();
    }
};

int main() {
    Solution sol;

    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped1 = {4, 5, 3, 2, 1};
    vector<int> popped2 = {4, 3, 5, 1, 2};

    cout << "Test 1: " << (sol.validateStackSequences(pushed, popped1) ? "true" : "false") << endl;
    cout << "Test 2: " << (sol.validateStackSequences(pushed, popped2) ? "true" : "false") << endl;

    return 0;
}
