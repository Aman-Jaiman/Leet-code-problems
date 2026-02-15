#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for(int num : st) {   // iterate over set (better than nums)
            // check if this is start of a sequence
            if(st.find(num - 1) == st.end()) {
                int currentNum = num;
                int count = 1;

                while(st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << obj.longestConsecutive(nums) << endl;
    return 0;
}