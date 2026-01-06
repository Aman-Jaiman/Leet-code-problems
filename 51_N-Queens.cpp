/*
---------------------------------------------------------
Problem: N-Queens

The N-Queens puzzle is the problem of placing N queens on
an N×N chessboard such that no two queens attack each other.

A queen can attack:
1. Same column
2. Same diagonal

Return all distinct solutions to the N-Queens problem.
---------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string>& board, int row, int n,
               vector<vector<string>>& ans) {

        // Base case
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing queen in each column
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, row + 1, n, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(board, 0, n, ans);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    Solution obj;
    vector<vector<string>> result = obj.solveNQueens(n);

    cout << "\nTotal Solutions: " << result.size() << "\n\n";

    for (int i = 0; i < result.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (string row : result[i]) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
