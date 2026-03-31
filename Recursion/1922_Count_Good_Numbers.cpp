#include <iostream>
using namespace std;

class Solution {
public:
    long long mod = 1000000007;

    long long power(long long base, long long exp) {
        if (exp == 0) return 1;

        long long half = power(base, exp / 2);
        long long result = (half * half) % mod;

        if (exp % 2 == 1)
            result = (result * base) % mod;

        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans = (power(5, even) * power(4, odd)) % mod;
        return ans;
    }
};

int main() {
    Solution obj;

    long long n = 4;
    cout << obj.countGoodNumbers(n) << endl;

    return 0;
}