#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstring(string s) {
        int n = s.size();
        if (n < 3) return 0;

        int l = 0, ans = 0;
        int count[3] = {0};

        for (int r = 0; r < n; r++) {
            count[s[r] - 'a']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                ans += (n - r);
                count[s[l] - 'a']--;
                l++;
            }
        }

        return ans;
    }
};