#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long solve(string &s, int i, long long num, int sign){

        if(i >= s.size() || !isdigit(s[i]))
            return sign * num;

        int digit = s[i] - '0';

        // overflow check
        if(num > (LLONG_MAX/10)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        num = num * 10 + digit;

        if(sign * num > INT_MAX) return INT_MAX;
        if(sign * num < INT_MIN) return INT_MIN;

        return solve(s, i + 1, num, sign);
    }

    int myAtoi(string s) {

        int i = 0;
        int sign = 1;

        while(i < s.size() && s[i] == ' ')
            i++;

        if(i < s.size() && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -1;
            i++;
        }

        return (int)solve(s, i, 0, sign);
    }
};
