// File: 20. Valid Parentheses.cpp
//
// Problem Statement:
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.
//
// A string is valid if:
// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.
// 3. Every closing bracket must have a corresponding previous opening bracket.
//
// Examples:
// Input: s = "()"
// Output: true
//
// Input: s = "()[]{}"
// Output: true
//
// Input: s = "(]"
// Output: false
//
// Input: s = "([)]"
// Output: false
//
// Input: s = "{[]}"
// Output: true
//
// Constraints:
// - 1 <= s.length <= 10^4
// - s consists of parentheses only '()[]{}'.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            // If opening bracket, push to stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            // If closing bracket
            else {
                // Stack khali hai but closing bracket aa gaya -> invalid
                if (st.empty()) return false;

                char top = st.top();
                // Check correct matching pair
                if ((top == '(' && ch == ')') ||
                    (top == '{' && ch == '}') ||
                    (top == '[' && ch == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        // Agar end me stack empty hai -> sab brackets properly close ho gaye
        return st.empty();
    }
};

int main() {
    string s;
    // Input ek hi string hogi jaise "()[]{}", "{[]}", "([)]", etc.
    cin >> s;

    Solution sol;
    bool ans = sol.isValid(s);

    if (ans) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}

