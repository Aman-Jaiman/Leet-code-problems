#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int prec(char c){
        if(c=='^') return 3;
        if(c=='*' || c=='/') return 2;
        if(c=='+' || c=='-') return 1;
        return -1;
    }

    string infixToPrefix(string &s){

        reverse(s.begin(), s.end());

        stack<char> st;
        string postfix="";

        for(char c : s){

            if(isalnum(c))
                postfix += c;

            else if(c==')')
                st.push(c);

            else if(c=='('){
                while(!st.empty() && st.top()!=')'){
                    postfix += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }

            else{
                while(!st.empty() &&
                      (prec(st.top()) > prec(c) ||
                      (prec(st.top()) == prec(c) && c=='^'))){
                    
                    postfix += st.top();
                    st.pop();
                }

                st.push(c);
            }
        }

        while(!st.empty()){
            postfix += st.top();
            st.pop();
        }

        reverse(postfix.begin(), postfix.end());

        return postfix;
    }
};