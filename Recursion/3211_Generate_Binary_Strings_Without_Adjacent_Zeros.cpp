#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;

    void f(int i, int n, string &s) {
        if (i == n) {
            ans.push_back(s);
            return;
        }

        // add 1
        s.push_back('1');
        f(i + 1, n, s);
        s.pop_back();

        // add 0 only if previous char is not 0
        if (i == 0 || s.back() == '1') {
            s.push_back('0');
            f(i + 1, n, s);
            s.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        string s = "";
        f(0, n, s);
        return ans;
    }
};