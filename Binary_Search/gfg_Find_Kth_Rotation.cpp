#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int st = 0;
        int end = arr.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] > arr[end]) {
                st = mid + 1;      // minimum in right half
            } else {
                end = mid;         // minimum in left half (including mid)
            }
        }

        return st;  // index of minimum element = number of rotations
    }
};

int main() {
    Solution obj;

    vector<int> arr = {4, 5, 1, 2, 3};

    cout << "Number of rotations: "
         << obj.findKRotation(arr) << endl;

    return 0;
}