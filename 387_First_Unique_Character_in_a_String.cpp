#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;

        // Count frequency of each character
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }

        // Find first character with frequency 1
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
