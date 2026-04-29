#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;  // base case

        int count = 0, ans = 0;

        for(int num : nums){
            if(num % 2 != 0) count++;

            if(mp.find(count - k) != mp.end()){
                ans += mp[count - k];
            }

            mp[count]++;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // Example 3
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;

    cout << obj.numberOfSubarrays(nums, k) << endl;

    return 0;
}