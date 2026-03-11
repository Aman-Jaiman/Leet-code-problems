#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int st = 0;
        int end = arr.size() - 1;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] >= x) {
                ans = mid;        // possible ceil
                end = mid - 1;    // search left for first occurrence
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {1, 2, 8, 10, 11, 11, 14, 19};
    int x = 11;

    int result = obj.findCeil(arr, x);

    cout << "Ceil Index: " << result << endl;

    if(result != -1)
        cout << "Ceil Value: " << arr[result] << endl;

    return 0;
}