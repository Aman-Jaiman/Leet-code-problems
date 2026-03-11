/*
74. Search a 2D Matrix
----------------------

You are given an m x n integer matrix "matrix" with the following two properties:

1. Each row is sorted in non-decreasing order.
2. The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix, or false otherwise.

-------------------------------------------------
Example 1:
Input:
matrix = [[1,3,5,7],
          [10,11,16,20],
          [23,30,34,60]], 
target = 3

Output: true

-------------------------------------------------
Example 2:
Input:
matrix = [[1,3,5,7],
          [10,11,16,20],
          [23,30,34,60]], 
target = 13

Output: false

-------------------------------------------------
Constraints:
- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 100
- -10^4 <= matrix[i][j], target <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();       // number of rows
        int n = matrix[0].size();    // number of columns

        // Treat the 2D matrix as a sorted 1D array
        int left = 0, right = m * n - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            // Map 1D index -> 2D indices
            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target) {
                return true;
            } else if(matrix[row][col] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target = 3;

    cout << (sol.searchMatrix(matrix, target) ? "true" : "false") << endl;

    return 0;
}
