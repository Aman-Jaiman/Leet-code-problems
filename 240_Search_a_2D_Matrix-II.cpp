/*
74. Search a 2D Matrix
----------------------
We are given an m x n matrix where:
1. Each row is sorted in ascending order.
2. The first element of each row is greater than the last element of the previous row.

Task: Given a target integer, return true if target exists in the matrix, else false.

Approach (Row–Column Search):
- Start from the top-right element (row = 0, col = n-1).
- If target == matrix[row][col] → found.
- If target < matrix[row][col] → move left (col--).
- If target > matrix[row][col] → move down (row++).
- Continue until row < m and col >= 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();        // number of rows
        int cols = matrix[0].size();     // number of columns

        int row = 0;         // start row (top)
        int col = cols - 1;  // start column (rightmost)

        // Search until indices are valid
        while(row < rows && col >= 0) {
            if(matrix[row][col] == target) {
                return true;   // target found
            }
            else if(matrix[row][col] > target) {
                col--;         // eliminate current column
            }
            else {
                row++;         // eliminate current row
            }
        }

        return false; // target not found
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 16;

    cout << (sol.searchMatrix(matrix, target) ? "true" : "false") << endl;
    return 0;
}
