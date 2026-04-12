#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;

    void helper(string &num, int index, long long value, long long prev, string path, int target) {

        if(index == num.size()) {
            if(value == target)
                ans.push_back(path);
            return;
        }

        for(int i = index; i < num.size(); i++) {

            // avoid numbers like 05
            if(i > index && num[index] == '0') break;

            string s = num.substr(index, i - index + 1);
            long long curr = stoll(s);

            if(index == 0) {
                helper(num, i + 1, curr, curr, s, target);
            }
            else {

                helper(num, i + 1, value + curr, curr, path + "+" + s, target);

                helper(num, i + 1, value - curr, -curr, path + "-" + s, target);

                helper(num, i + 1, value - prev + prev * curr, prev * curr, path + "*" + s, target);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        helper(num, 0, 0, 0, "", target);
        return ans;
    }
};