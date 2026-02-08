#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                return true;   // At least one vowel → Alice wins
            }
        }
        return false;          // No vowels → Alice loses
    }
};

// Optional main() for local testing
int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << (sol.doesAliceWin(s) ? "true" : "false") << endl;
    return 0;
}
