/*
LeetCode 151. Reverse Words in a String
------------------------------------------------------
Question:
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters.
Words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note:
- s may contain leading or trailing spaces.
- Multiple spaces between two words should be reduced to a single space.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space.

Constraints:
- 1 <= s.length <= 10^4
- s contains English letters (upper-case and lower-case), digits, and spaces ' '.
- There is at least one word in s.
------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        string ans = "";
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++)
        {
            string word = "";
            while (i < n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if (word.length() > 0)
            {
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};

int main()
{
    Solution sol;

    string s1 = "the sky is blue";
    cout << "Input: \"" << s1 << "\"\nOutput: \""
         << sol.reverseWords(s1) << "\"\n\n";

    string s2 = "  hello world  ";
    cout << "Input: \"" << s2 << "\"\nOutput: \""
         << sol.reverseWords(s2) << "\"\n\n";

    string s3 = "a good   example";
    cout << "Input: \"" << s3 << "\"\nOutput: \""
         << sol.reverseWords(s3) << "\"\n";

    return 0;
}
