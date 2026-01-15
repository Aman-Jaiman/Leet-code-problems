#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        long long st = 1, end = x, ans = 0;

        while (st <= end) {
            long long mid = st + (end - st) / 2;

            if (mid * mid == x) {
                return mid;
            }
            else if (mid * mid < x) {
                ans = mid;        // possible answer
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int x;
    cout << "Enter a number: ";
    cin >> x;

    cout << "Square root (floor): " << sol.mySqrt(x) << endl;
    return 0;
}
