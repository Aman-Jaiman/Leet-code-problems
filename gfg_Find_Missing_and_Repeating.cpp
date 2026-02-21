#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {

        long long n = arr.size();

        long long sumA = 0, sumSqA = 0;

        // Calculate sum and sum of squares of array
        for(int i = 0; i < n; i++) {
            sumA += arr[i];
            sumSqA += (long long)arr[i] * arr[i];
        }

        // Expected sum and square sum
        long long sum = n * (n + 1) / 2;
        long long sumSq = n * (n + 1) * (2*n + 1) / 6;

        long long diff = sumA - sum;          // R - M
        long long diffSq = sumSqA - sumSq;    // R² - M²

        long long sumRM = diffSq / diff;      // R + M

        long long R = (diff + sumRM) / 2;
        long long M = sumRM - R;

        return {(int)R, (int)M};
    }
};
