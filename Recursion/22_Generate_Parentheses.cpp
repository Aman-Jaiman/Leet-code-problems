#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void generate(int open, int close, int n, string str, vector<string>& ans) {
        if (str.length() == 2 * n) {
            ans.push_back(str);
            return;
        }

        if (open < n) {
            generate(open + 1, close, n, str + "(", ans);
        }

        if (close < open) {
            generate(open, close + 1, n, str + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(0, 0, n, "", ans);
        return ans;
    }
};

int main() {
    Solution obj;
    int n;
    cin >> n;

    vector<string> result = obj.generateParenthesis(n);

    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}