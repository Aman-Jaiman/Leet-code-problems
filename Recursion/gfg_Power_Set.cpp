#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<string> ans;
    
    void solve(string &s, int i, string str){
        if(i == s.size()){
            if(str.size() > 0)
                ans.push_back(str);
            return;
        }
        
        // include current character
        solve(s, i + 1, str + s[i]);
        
        // exclude current character
        solve(s, i + 1, str);
    }
    
    vector<string> AllPossibleStrings(string s) {
        solve(s, 0, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution obj;
    string s;
    cin >> s;

    vector<string> result = obj.AllPossibleStrings(s);

    for(string str : result){
        cout << str << " ";
    }

    return 0;
}