#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;

        for (char ch : columnTitle) {
            int value = ch - 'A' + 1;
            ans = ans * 26 + value;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string columnTitle;
    cout << "Enter column title: ";
    cin >> columnTitle;

    cout << "Column Number: "
         << sol.titleToNumber(columnTitle) << endl;

    return 0;
}
