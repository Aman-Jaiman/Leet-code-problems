#include <cmath>

class Solution {
public:
    int nthRoot(int n, int m) {

        int st = 1;
        int end = m;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            long long ans = pow(mid, n);

            if(ans == m) {
                return mid;
            }
            else if(ans > m) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return -1;
    }
};