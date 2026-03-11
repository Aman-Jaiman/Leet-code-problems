/*
204. Count Primes

Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0

Constraints:
- 0 <= n <= 5 * 10^6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        
        for(int i = 2; i * i < n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        return count(isPrime.begin(), isPrime.end(), true);
    }
};

int main() {
    Solution sol;
    
    int n1 = 10;
    cout << "Input: " << n1 << " -> Count of primes: " << sol.countPrimes(n1) << endl;
    
    int n2 = 0;
    cout << "Input: " << n2 << " -> Count of primes: " << sol.countPrimes(n2) << endl;
    
    int n3 = 1;
    cout << "Input: " << n3 << " -> Count of primes: " << sol.countPrimes(n3) << endl;
    
    int n4 = 20;
    cout << "Input: " << n4 << " -> Count of primes: " << sol.countPrimes(n4) << endl;
    
    return 0;
}

