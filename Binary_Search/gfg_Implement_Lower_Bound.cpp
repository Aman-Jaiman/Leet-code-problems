#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int st = 0;
        int end = arr.size();   // important: end = n

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] < target) {
                st = mid + 1;
            } else {
                end = mid;
            }
        }

        return st;   // first index where arr[i] >= target
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 4, 4, 5, 7};
    int target = 4;

    int index = sol.lowerBound(arr, target);

    cout << "Lower Bound Index: " << index << endl;

    if (index < arr.size())
        cout << "Value at Lower Bound: " << arr[index] << endl;
    else
        cout << "Target greater than all elements" << endl;

    return 0;
}