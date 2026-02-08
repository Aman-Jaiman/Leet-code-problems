#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        int freqV = 0, freqC = 0;
        string vol = "aeiou";

        // count frequencies
        for (char c : s) {
            freq[c - 'a']++;
        }

        // find max vowel and consonant frequency
        for (int i = 0; i < 26; i++) {
            char ch = i + 'a';
            if (vol.find(ch) != string::npos) {
                freqV = max(freqV, freq[i]);
            } else {
                freqC = max(freqC, freq[i]);
            }
        }

        return freqV + freqC;
    }
};

