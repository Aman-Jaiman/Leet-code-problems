#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string str = "";
        while (n > 0) {
            n--;                          // important step
            char ch = 'A' + (n % 26);
            str.push_back(ch);
            n /= 26;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

int main() {
    Solution sol;

    int columnNumber;
    cout << "Enter column number: ";
    cin >> columnNumber;

    cout << "Excel Column Title: "
         << sol.convertToTitle(columnNumber) << endl;

    return 0;
}
