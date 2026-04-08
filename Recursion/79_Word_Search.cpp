#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(vector<vector<char>>& board, string &word, int i, int j, int k) {

        if(k == word.size()) return true;

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
           || board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '#'; // mark visited

        bool found =
            helper(board, word, i+1, j, k+1) ||
            helper(board, word, i-1, j, k+1) ||
            helper(board, word, i, j+1, k+1) ||
            helper(board, word, i, j-1, k+1);

        board[i][j] = temp; // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(helper(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};

int main() {

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    Solution obj;

    if(obj.exist(board, word))
        cout << "Word Found\n";
    else
        cout << "Word Not Found\n";

    return 0;
}