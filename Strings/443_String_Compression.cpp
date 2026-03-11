/*
443. String Compression

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:
    - If the group's length is 1, append the character to s.
    - Otherwise, append the character followed by the group's length.

The compressed string s should not be returned separately, but instead be stored in the input character array chars. 
Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Example 2:
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]

Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"]

Constraints:
- 1 <= chars.length <= 2000
- chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0; // index to place compressed characters
        
        for(int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;
            
            // count the frequency of the current character
            while(i < n && chars[i] == ch) {
                i++;
                count++;
            }
            
            // store the character
            chars[idx++] = ch;
            
            // if frequency > 1, store its digits
            if(count > 1) {
                string str = to_string(count);
                for(char digit : str) {
                    chars[idx++] = digit;
                }
            }
            
            i--; // adjust index because the outer loop also increments i
        }
        
        // resize array to the new length
        chars.resize(idx);
        return idx;
    }
};

int main() {
    Solution sol;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    
    int newLength = sol.compress(chars);
    
    cout << "Compressed length: " << newLength << endl;
    cout << "Compressed array: ";
    for(int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;
    
    return 0;
}
