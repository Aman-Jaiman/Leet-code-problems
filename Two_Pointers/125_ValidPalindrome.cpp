// 125_ValidPalindrome_two_pointer.cpp
/*
LeetCode 125: Valid Palindrome
Convert uppercase to lowercase and remove non-alphanumeric characters,
then check if the string reads the same forward and backward.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0 , right = s.length()-1;
        while(left<=right){  
            if(isalnum(s[left]) && isalnum(s[right])){
                if(tolower(s[left])!=tolower(s[right])) return false;
                left++;
                right--;
            }else{
                if(!(isalnum(s[left])))  left++;
                if(!(isalnum(s[right])))  right--;
            }
        }
        return true;
    }
};


int main() {
    Solution sol;
    vector<string> tests = {
        "A man, a plan, a canal: Panama",
        "race a car",
        "0P",
        " ",
        "Madam"
    };

    for (auto &t : tests) {
        cout << "\"" << t << "\" -> " << (sol.isPalindrome(t) ? "true" : "false") << '\n';
    }
    return 0;
}
