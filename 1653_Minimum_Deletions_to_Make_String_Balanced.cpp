#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int countB = 0;
        int deletions = 0;

        for (char c : s) {
            if (c == 'b') {
                countB++;
            } else { // c == 'a'
                deletions = min(deletions + 1, countB);
            }
        }

        return deletions;
    }
};

// Optional main function for local testing
int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.minimumDeletions(s) << endl;
    return 0;
}
