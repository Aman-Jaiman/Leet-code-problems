#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canPaint(vector<int>& arr, int mid, int k) {
        int painter = 1;
        int sum = arr[0];

        for(int i = 1; i < arr.size(); i++) {
            sum += arr[i];

            if(sum > mid) {
                painter++;
                if(painter > k) return false;
                sum = arr[i];
            }
        }

        return true;
    }

    int minTime(vector<int>& arr, int k) {

        int st = *max_element(arr.begin(), arr.end());
        int end = 0;

        for(int i = 0; i < arr.size(); i++) {
            end += arr[i];
        }

        int ans = end;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(canPaint(arr, mid, k)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {5, 10, 30, 20, 15};
    int k = 3;

    cout << "Minimum time to paint boards: " << obj.minTime(arr, k) << endl;

    return 0;
}