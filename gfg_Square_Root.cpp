#include <iostream>
using namespace std;

int floorSqrt(int n) {
    if(n == 0) return 0;

    int st = 1;
    int end = n;
    int ans = 1;

    while(st <= end) {
        int mid = st + (end - st) / 2;

        if(mid == n / mid) {
            return mid;
        }
        else if(mid > n / mid) {
            end = mid - 1;
        }
        else {
            ans = mid;
            st = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Floor sqrt: " << floorSqrt(n);

    return 0;
}