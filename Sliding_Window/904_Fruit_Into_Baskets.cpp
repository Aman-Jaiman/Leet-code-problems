#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int left = 0, ans = 0;

        for (int right = 0; right < fruits.size(); right++) {
            mp[fruits[right]]++;

            // shrink window if more than 2 types
            while (mp.size() > 2) {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> fruits = {1, 2, 3, 2, 2};
    cout << sol.totalFruit(fruits) << endl;  // Output: 4

    return 0;
}