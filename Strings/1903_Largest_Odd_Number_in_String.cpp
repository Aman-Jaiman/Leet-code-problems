#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size() - 1; i >= 0; i--){
            if((num[i] - '0') % 2 == 1){
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main() {
    Solution obj;
    string num = "35427";
    cout << obj.largestOddNumber(num);
    return 0;
}