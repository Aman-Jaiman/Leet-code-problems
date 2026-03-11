#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int upperBound(vector<int>& arr, int target) {
        int st = 0;
        int end = arr.size();   // half-open range [0, n)

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] <= target) {
                st = mid + 1;
            } else {
                end = mid;
            }
        }
        return st;
    }
};

int main() {
    Solution obj;
    
    vector<int> arr = {1, 2, 4, 4, 5, 7};
    int target = 4;

    int result = obj.upperBound(arr, target);
    
    cout << "Upper Bound Index: " << result << endl;

    return 0;
}