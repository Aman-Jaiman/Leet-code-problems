#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word,
             int i, int j, int idx) {

        // Base case: all characters matched
        if (idx == word.size())
            return true;

        // Boundary and mismatch checks
        if (i < 0 || j < 0 ||
            i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[idx])
            return false;

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 directions
        bool found =
            dfs(board, word, i - 1, j, idx + 1) ||
            dfs(board, word, i + 1, j, idx + 1) ||
            dfs(board, word, i, j - 1, idx + 1) ||
            dfs(board, word, i, j + 1, idx + 1);

        // Backtrack: restore original value
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    if (sol.exist(board, word))
        cout << "Word exists in board\n";
    else
        cout << "Word does not exist in board\n";

    return 0;
}
