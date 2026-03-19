#include <iostream>
#include <string>
using namespace std;
class Solution {
public:

    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=1;j++){// for (i,i) and (i,i+1)
                int low=i;
                int high=i+j;
                while(low>=0 && high<n && s[low]==s[high]){
                    int currLen = high - low + 1;
                    if(currLen>maxLen){
                        start=low;
                        maxLen=currLen;
                    }
                    low--;
                    high++;
                }
            }
        }
        
        return s.substr(start,maxLen);
    }
};