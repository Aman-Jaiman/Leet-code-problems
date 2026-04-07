#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> vec;

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void helper(string &s, int start) {
        if (start == s.size()) {
            ans.push_back(vec);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                vec.push_back(s.substr(start, end - start + 1));
                helper(s, end + 1);
                vec.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        helper(s, 0);
        return ans;
    }
};