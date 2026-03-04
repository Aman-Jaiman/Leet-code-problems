#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int st = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        int ans = end;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            int totalDay = 1;
            int weight = 0;

            for(int i = 0; i < weights.size(); i++) {

                if(weight + weights[i] > mid) {
                    totalDay++;
                    weight = weights[i];
                }
                else {
                    weight += weights[i];
                }
            }

            if(totalDay > days) {
                st = mid + 1;
            }
            else {
                ans = mid;
                end = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout << "Minimum ship capacity: "
         << obj.shipWithinDays(weights, days) << endl;

    return 0;
}