/*
Problem: Largest 3-Digit Number in a String

You are given a string num consisting of digits only.
A "good integer" is a substring of length 3 such that all
three characters are equal.

Return the largest good integer as a string.
If no good integer exists, return an empty string.

Examples:
Input: "6777133339"
Output: "777"

Input: "2300019"
Output: "000"

Input: "42352338"
Output: ""

LeetCode Problem: 2264
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char best = '0';
        bool found = false;

        for (int i = 0; i + 2 < num.length(); i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                final_check:
                best = max(best, num[i]);
                found = true;
            }
        }

        if (!found) return "";
        return string(3, best);
    }
};

int main() {
    Solution sol;

    cout << sol.largestGoodInteger("6777133339") << endl; // 777
    cout << sol.largestGoodInteger("2300019") << endl;   // 000
    cout << sol.largestGoodInteger("42352338") << endl;  // ""
    cout << sol.largestGoodInteger("111") << endl;       // 111
    cout << sol.largestGoodInteger("000") << endl;       // 000

    return 0;
}
