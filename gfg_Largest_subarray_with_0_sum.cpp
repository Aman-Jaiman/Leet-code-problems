#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;
        int sum = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            sum += arr[i];

            // If sum becomes 0, subarray from 0 to i has sum 0
            if(sum == 0)
                ans = i + 1;

            // If sum seen before
            if(m.find(sum) != m.end()){
                ans = max(ans, i - m[sum]);
            }
            else{
                // Store first occurrence only
                m[sum] = i;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, -1, 3, 2, -2, -3, 3};
    
    cout << obj.maxLength(arr) << endl;
    
    return 0;
}
