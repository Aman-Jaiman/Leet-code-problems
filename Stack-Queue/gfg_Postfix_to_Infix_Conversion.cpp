#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string postToInfix(string &exp) {

        stack<string> st;

        for(char c : exp) {

            // if operand
            if(isalnum(c)) {
                st.push(string(1,c));
            }

            // if operator
            else {

                string op1 = st.top();
                st.pop();

                string op2 = st.top();
                st.pop();

                string temp = "(" + op2 + string(1,c) + op1 + ")";

                st.push(temp);
            }
        }

        return st.top();
    }
};

int main() {

    Solution obj;

    string exp = "AB+CD-*";

    cout << obj.postToInfix(exp);

    return 0;
}