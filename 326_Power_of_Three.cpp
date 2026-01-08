/*
Problem: Power of Three

Given an integer n, return true if it is a power of three.
Otherwise, return false.

An integer n is a power of three if there exists an integer x such that:
n == 3^x

Example 1:
Input: n = 27
Output: true

Example 2:
Input: n = 0
Output: false

Example 3:
Input: n = 9
Output: true

LeetCode Problem: 326. Power of Three
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
       
       class Solution {
public:

        // if (n <= 0) return false;

        // while (n % 3 == 0) {
        //     n /= 3;
        // }

        // return n == 1;

        long long x=1;
        while(n>=x){
            if(n-x==0) return true;
            x=x*3;
        }
        return false;
    }
};

int main() {
    Solution sol;

    cout << sol.isPowerOfThree(27) << endl; // 1 (true)
    cout << sol.isPowerOfThree(9) << endl;  // 1 (true)
    cout << sol.isPowerOfThree(1) << endl;  // 1 (true)
    cout << sol.isPowerOfThree(0) << endl;  // 0 (false)
    cout << sol.isPowerOfThree(10) << endl; // 0 (false)

    return 0;
}
