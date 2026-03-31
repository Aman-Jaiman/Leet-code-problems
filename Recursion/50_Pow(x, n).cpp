#include <iostream>
using namespace std;

class Solution {
public:

    double result(double x, long long n) {
        if (n == 0) return 1;

        double half = result(x, n / 2);

        if (n % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }

    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return result(x, N);
    }
};

int main() {
    Solution sol;

    double x = 2.0;
    int n = 10;

    cout << sol.myPow(x, n) << endl;

    return 0;
}