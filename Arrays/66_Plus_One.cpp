/*
    LeetCode Problem 66: Plus One

    You are given a large integer represented as an integer array `digits`,
    where each digits[i] is the i-th digit of the integer.
    The digits are ordered from most significant to least significant in left-to-right order.

    The large integer does not contain any leading 0s.

    Increment the large integer by one and return the resulting array of digits.

    Example:
    Input: digits = [1,2,3]
    Output: [1,2,4]

    Input: digits = [9,9]
    Output: [1,0,0]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from the last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++; // Just increment and return
                return digits;
            }
            digits[i] = 0; // 9 becomes 0, carry continues
        }

        // If all digits were 9 → new digit needed at beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    int n;
    cout << "Enter number of digits: ";
    cin >> n;

    vector<int> digits(n);
    cout << "Enter digits: ";
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    Solution obj;
    vector<int> result = obj.plusOne(digits);

    cout << "Result: ";
    for (int d : result) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
