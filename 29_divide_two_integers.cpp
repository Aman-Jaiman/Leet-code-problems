/*
Problem: Divide Two Integers (LeetCode #29)

Given two integers dividend and divisor, divide two integers without using
multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part.
For example: 
    8 / 3 = 2
    -8 / 3 = -2

Constraints:
1. Both dividend and divisor are 32-bit signed integers.
2. Divisor will never be 0.
3. Result should be clamped to the range [-2^31, 2^31 - 1].

Example 1:
Input: dividend = 10, divisor = 3
Output: 3

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
*/

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Convert to long long to handle abs(INT_MIN)
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long result = 0;

        // Subtract divisor multiples using bit shifts
        while (a >= b) {
            long long temp = b, multiple = 1;
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0)) result = -result;

        // Clamp result
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int)result;
    }
};

int main() {
    Solution sol;

    int dividend, divisor;
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;

    int result = sol.divide(dividend, divisor);
    cout << "Quotient = " << result << endl;

    return 0;
}
