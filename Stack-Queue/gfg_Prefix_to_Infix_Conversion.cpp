#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
    
        reverse(pre_exp.begin(),pre_exp.end());
        stack<string>st;
        for(char c:pre_exp){
            if(isalnum(c)){
                st.push(string(1,c));
            }
            else{
                string op1 = st.top(); 
                st.pop();
                string op2 = st.top(); 
                st.pop();
                string temp = "(" + op1 + c + op2 + ")";
                st.push(temp);
            }
        }
        
        return st.top();
    }
};