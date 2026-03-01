#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int st = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = end;

        while(st <= end){
            int mid = st + (end - st) / 2;
            long long totalH = 0;

            // Calculate total hours needed at speed mid
            for(int i = 0; i < piles.size(); i++){
                totalH += (piles[i] + mid - 1) / mid;  // ceil division
            }

            if(totalH <= h){
                ans = mid;        // possible answer
                end = mid - 1;    // try smaller speed
            }
            else{
                st = mid + 1;     // need higher speed
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << "Minimum Eating Speed: "
         << obj.minEatingSpeed(piles, h) << endl;

    return 0;
}