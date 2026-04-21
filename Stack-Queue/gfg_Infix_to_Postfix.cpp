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

    bool isRightAssociative(char c){
        return c=='^';
    }

    string infixToPostfix(string s){
        stack<char> st;
        string postfix="";

        for(int i=0;i<s.size();i++){
            char c=s[i];

            // operand
            if(isalnum(c)){
                postfix+=c;
            }

            // opening bracket
            else if(c=='('){
                st.push(c);
            }

            // closing bracket
            else if(c==')'){
                while(!st.empty() && st.top()!='('){
                    postfix+=st.top();
                    st.pop();
                }
                st.pop();
            }

            // operator
            else{
                while(!st.empty() && 
                     (prec(st.top()) > prec(c) ||
                     (prec(st.top()) == prec(c) && !isRightAssociative(c)))){
                    
                    postfix+=st.top();
                    st.pop();
                }

                st.push(c);
            }
        }

        // pop remaining operators
        while(!st.empty()){
            postfix+=st.top();
            st.pop();
        }

        return postfix;
    }
};

int main(){
    
    Solution obj;
    
    string s="(A+B)*(C-D)";
    
    cout<<obj.infixToPostfix(s);

    return 0;
}