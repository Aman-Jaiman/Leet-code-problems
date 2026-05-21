#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;

        // Top and bottom rows
        for (int i = 0; i < n; i++) {

            if (board[0][i] == 'O') {
                board[0][i] = '#';
                q.push({0, i});
            }

            if (board[m-1][i] == 'O') {
                board[m-1][i] = '#';
                q.push({m-1, i});
            }
        }

        // Left and right columns
        for (int i = 0; i < m; i++) {

            if (board[i][0] == 'O') {
                board[i][0] = '#';
                q.push({i, 0});
            }

            if (board[i][n-1] == 'O') {
                board[i][n-1] = '#';
                q.push({i, n-1});
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // BFS
        while (!q.empty()) {

            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            for (int i = 0; i < 4; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 &&
                    ncol >= 0 &&
                    nrow < m &&
                    ncol < n &&
                    board[nrow][ncol] == 'O') {

                    board[nrow][ncol] = '#';

                    q.push({nrow, ncol});
                }
            }
        }

        // Final conversion
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }

                else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main() {

    Solution obj;

    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    obj.solve(board);

    for (auto row : board) {

        for (auto ch : row) {
            cout << ch << " ";
        }

        cout << endl;
    }

    return 0;
}