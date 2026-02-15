#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        
        int ans = 0;
        int count = 0;
        
        for (int num : arr) {
            if (num == 1) {
                count++;
                ans = max(ans, count);
            } 
            else {
                count = 0;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution obj;
    
    vector<int> arr = {1, 1, 0, 1, 1, 1};
    
    cout << "Maximum Consecutive Ones: "
         << obj.findMaxConsecutiveOnes(arr);
    
    return 0;
}