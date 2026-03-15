#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};

        if(s.size() != t.size()) return false;

        for(int i = 0; i < s.size(); i++){
            int c1 = s[i] - 'a';
            int c2 = t[i] - 'a';

            arr[c1]++;
            arr[c2]--;
        }

        for(int i = 0; i < 26; i++){
            if(arr[i] != 0) return false;
        }

        return true;
    }
};