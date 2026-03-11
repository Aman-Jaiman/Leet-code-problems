/*
54. Spiral Matrix
-----------------
Given an m x n matrix, return all elements of the matrix in spiral order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int rows = matrix.size();        // total rows
        int cols = matrix[0].size();     // total columns

        int startRow = 0, startCol = 0;  // starting row and column
        int endRow = rows - 1, endCol = cols - 1; // ending row and column

        while(startRow <= endRow && startCol <= endCol) {

            // 1. Traverse Top Row (left to right)
            for(int col = startCol; col <= endCol; col++) {
                result.push_back(matrix[startRow][col]);
            }

            // 2. Traverse Right Column (top to bottom)
            for(int row = startRow + 1; row <= endRow; row++) {
                result.push_back(matrix[row][endCol]);
            }

            // 3. Traverse Bottom Row (right to left) -> only if more than one row
            if(startRow < endRow) {
                for(int col = endCol - 1; col >= startCol; col--) {
                    result.push_back(matrix[endRow][col]);
                }
            }

            // 4. Traverse Left Column (bottom to top) -> only if more than one column
            if(startCol < endCol) {
                for(int row = endRow - 1; row > startRow; row--) {
                    result.push_back(matrix[row][startCol]);
                }
            }

            // Move boundaries inward
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }

        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> ans = sol.spiralOrder(matrix);

    cout << "Spiral Order: ";
    for(int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
