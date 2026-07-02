/*
Problem: Multiply Strings (LeetCode #43)

Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.

Note:
1. The numbers should not be converted directly to integers (e.g., stoi, stoll).
2. You must handle very large numbers (up to 200 digits).
3. The result should not contain leading zeros, unless the result itself is "0".

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Constraints:
- 1 <= num1.length, num2.length <= 200
- num1 and num2 consist of digits only.
- Both num1 and num2 do not contain any leading zeros, except the number "0" itself.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> result(n1 + n2, 0);

        // Multiply digits like long multiplication
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;       // store single digit
                result[i + j] += sum / 10;          // carry
            }
        }

        // Convert result vector to string (skip leading zeros)
        string ans = "";
        for (int num : result) {
            if (!(ans.empty() && num == 0)) ans.push_back(num + '0');
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    cout << "Product = " << sol.multiply(num1, num2) << endl;
    return 0;
}
