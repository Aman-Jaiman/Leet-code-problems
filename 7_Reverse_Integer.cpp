// 7_Reverse_Int.cpp
// LeetCode Problem 7: Reverse Integer

/*
Problem Statement:
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 1534236469
Output: 0 (because it overflows)
*/

#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
    int ans = 0;
    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        // Check overflow before multiplying
        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) return 0;
        if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8)) return 0;

        ans = ans * 10 + digit;
    }
    return ans;
}

int main() {
    int x1 = 123;
    int x2 = -123;
    int x3 = 1534236469;

    cout << "Reverse of " << x1 << " is " << reverse(x1) << endl;
    cout << "Reverse of " << x2 << " is " << reverse(x2) << endl;
    cout << "Reverse of " << x3 << " is " << reverse(x3) << endl;
}
