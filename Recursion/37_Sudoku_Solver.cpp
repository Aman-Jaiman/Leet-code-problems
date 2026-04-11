#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {

        for(int i = 0; i < 9; i++) {

            // check row
            if(board[row][i] == num) return false;

            // check column
            if(board[i][col] == num) return false;

            // check 3x3 box
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == num)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') {

                    for(char num = '1'; num <= '9'; num++) {

                        if(isValid(board, i, j, num)) {

                            board[i][j] = num;

                            if(solve(board))
                                return true;

                            board[i][j] = '.'; // backtrack
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};