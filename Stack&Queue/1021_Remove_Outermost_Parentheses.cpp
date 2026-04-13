#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
       int dept = 0;
       string ans = "";

       for(int i = 0; i < s.size(); i++){
           if(s[i] == '('){
               if(dept != 0) ans += s[i];
               dept++;
           }
           else{
               dept--;
               if(dept != 0) ans += s[i];
           }
       } 

       return ans;
    }
};