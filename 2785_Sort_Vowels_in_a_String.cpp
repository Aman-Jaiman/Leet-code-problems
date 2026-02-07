#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, int> freq;
        string order = "AEIOUaeiou";

        // collect vowels
        for (char c : s) {
            if (order.find(c) != string::npos) {
                freq[c]++;
            }
        }

        // place vowels back in ASCII order
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (order.find(s[i]) != string::npos) {
                while (freq[order[idx]] == 0) {
                    idx++;
                }
                s[i] = order[idx];
                freq[order[idx]]--;
            }
        }

        return s;
    }
};

// Optional: main function for local testing
int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.sortVowels(s) << endl;
    return 0;
}
