#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int firstOcc(vector<int>& arr, int target) {
        int st = 0, end = arr.size() - 1;
        int ans = -1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(arr[mid] == target) {
                ans = mid;
                end = mid - 1;  // move left
            }
            else if(arr[mid] > target) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }
        return ans;
    }

    int lastOcc(vector<int>& arr, int target) {
        int st = 0, end = arr.size() - 1;
        int ans = -1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(arr[mid] == target) {
                ans = mid;
                st = mid + 1;  // move right
            }
            else if(arr[mid] > target) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }
        return ans;
    }

    int countFreq(vector<int>& arr, int target) {
        int first = firstOcc(arr, target);
        if(first == -1) return 0;  // target not found

        int last = lastOcc(arr, target);
        return last - first + 1;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {1, 2, 8, 10, 11, 11, 14, 19};
    int target = 11;

    int result = obj.countFreq(arr, target);

    cout << "Frequency: " << result << endl;

    return 0;
}