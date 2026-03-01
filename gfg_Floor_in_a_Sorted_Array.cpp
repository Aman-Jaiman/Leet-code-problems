#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFloor(vector<int>& arr, int x) {
        int st = 0;
        int end = arr.size() - 1;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] > x) {
                end = mid - 1;
            } else {
                ans = mid;      // possible floor
                st = mid + 1;   // search right for larger valid
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {1, 2, 8, 10, 11, 11, 14, 19};
    int x = 11;

    int result = obj.findFloor(arr, x);

    cout << "Floor Index: " << result << endl;

    if(result != -1)
        cout << "Floor Value: " << arr[result] << endl;

    return 0;
}