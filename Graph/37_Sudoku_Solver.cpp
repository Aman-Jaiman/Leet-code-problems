/*
===========================================================
LeetCode 37. Sudoku Solver
===========================================================

Problem Statement:
------------------
Write a program to solve a Sudoku puzzle by filling the empty
cells.

A sudoku solution must satisfy all of the following rules:
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the
   9 sub-boxes of the grid.

Empty cells are indicated by the character '.'.

The solution must modify the board in-place.

-----------------------------------------------------------
Approach:
---------
Backtracking with recursion.
We try placing digits '1' to '9' in each empty cell and move
forward only if the placement is valid.
If no digit fits, we backtrack.
-----------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check whether placing 'dig' at board[row][col] is safe
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {

        // Horizontal (row) check
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig) return false;
        }

        // Vertical (column) check
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig) return false;
        }

        // 3x3 sub-grid check
        int sRow = (row / 3) * 3;
        int sCol = (col / 3) * 3;

        for (int i = sRow; i < sRow + 3; i++) {
            for (int j = sCol; j < sCol + 3; j++) {
                if (board[i][j] == dig) return false;
            }
        }

        return true;
    }

    // Recursive helper function
    bool helper(vector<vector<char>>& board, int row, int col) {

        // Base case: solved entire board
        if (row == 9) return true;

        int nextRow = row;
        int nextCol = col + 1;

        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        // If already filled, move to next cell
        if (board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        // Try digits from 1 to 9
        for (char dig = '1'; dig <= '9'; dig++) {
            if (isSafe(board, row, col, dig)) {
                board[row][col] = dig;

                if (helper(board, nextRow, nextCol))
                    return true;

                // Backtrack
                board[row][col] = '.';
            }
        }

        return false;
    }

    // LeetCode function
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};

/*
Note:
-----
• Time Complexity: Exponential (backtracking)
• Space Complexity: O(1) extra (recursion stack only)
• This solution is accepted on LeetCode.
*/
