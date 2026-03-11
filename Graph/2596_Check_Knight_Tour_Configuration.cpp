/*
Problem: Check Knight Tour Configuration

You are given an n x n integer grid.
The grid represents a knight's tour on a chessboard.

A knight starts at cell (0, 0) and makes moves according to
standard chess knight rules.

Each cell contains a unique number from 0 to n*n - 1.
The number represents the step at which the knight visits that cell.

Return true if the grid represents a valid knight's tour, else false.

Knight Moves:
(r ± 2, c ± 1) or (r ± 1, c ± 2)

LeetCode Problem: 2596. Check Knight Tour Configuration
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal) {
        // Boundary and value check
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal) {
            return false;
        }

        // If last value is reached
        if (expVal == n * n - 1) {
            return true;
        }

        // All 8 possible knight moves
        bool ans1 = isValid(grid, r - 2, c + 1, n, expVal + 1);
        bool ans2 = isValid(grid, r - 1, c + 2, n, expVal + 1);
        bool ans3 = isValid(grid, r + 1, c + 2, n, expVal + 1);
        bool ans4 = isValid(grid, r + 2, c + 1, n, expVal + 1);
        bool ans5 = isValid(grid, r + 2, c - 1, n, expVal + 1);
        bool ans6 = isValid(grid, r + 1, c - 2, n, expVal + 1);
        bool ans7 = isValid(grid, r - 1, c - 2, n, expVal + 1);
        bool ans8 = isValid(grid, r - 2, c - 1, n, expVal + 1);

        return ans1 || ans2 || ans3 || ans4 ||
               ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0, 59, 38, 33, 30, 17, 8, 63},
        {37, 34, 31, 60, 9, 62, 29, 16},
        {58, 1, 36, 39, 32, 27, 18, 7},
        {35, 48, 41, 26, 61, 10, 15, 28},
        {42, 57, 2, 49, 40, 23, 6, 19},
        {47, 50, 45, 54, 25, 20, 11, 14},
        {56, 43, 52, 3, 22, 13, 24, 5},
        {51, 46, 55, 44, 53, 4, 21, 12}
    };

    cout << (sol.checkValidGrid(grid) ? "Valid Knight Tour" : "Invalid Knight Tour");

    return 0;
}
