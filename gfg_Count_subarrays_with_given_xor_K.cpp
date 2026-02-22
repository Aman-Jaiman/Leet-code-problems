#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        long ans = 0;
        unordered_map<int,int> m;
        
        int xorr = 0;
        
        for(int i = 0; i < n; i++){
            xorr ^= arr[i];
            
            if(xorr == k)
                ans++;
                
            int prev = xorr ^ k;
            
            if(m.find(prev) != m.end()){
                ans += m[prev];   // ✅ FIXED (was m[xorr])
            }
            
            m[xorr]++;
        }
        
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    
    cout << obj.subarrayXor(arr, k) << endl;
    
    return 0;
}
