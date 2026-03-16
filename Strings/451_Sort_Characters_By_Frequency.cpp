#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string ans = "";

        vector<int> freq(128,0);

        for(char c : s){
            freq[c]++;
        }

        vector<pair<char,int>> vp;

        for(int i=0;i<128;i++){
            if(freq[i] > 0){
                vp.push_back({char(i), freq[i]});
            }
        }

        sort(vp.begin(), vp.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        for(auto p : vp){
            for(int i=0;i<p.second;i++){
                ans += p.first;
            }
        }

        return ans;
    }
};