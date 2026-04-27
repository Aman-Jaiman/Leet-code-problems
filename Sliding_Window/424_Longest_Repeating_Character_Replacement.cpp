#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int left = 0, ans = 0, maxFreq = 0;

        for (int right = 0; right < s.size(); right++) {
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);

            // shrink window if invalid
            while ((right - left + 1) - maxFreq > k) {
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s = "AABCAADKEAAC";
    int k = 2;

    cout << sol.characterReplacement(s, k) << endl; // Output: 6

    return 0;
}