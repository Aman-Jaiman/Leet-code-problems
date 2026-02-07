#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int row[3] = {}, col[3] = {};
        int dia = 0, anti = 0;

        for (int i = 0; i < moves.size(); i++) {
            int r = moves[i][0];
            int c = moves[i][1];

            int p = (i % 2 == 0) ? 1 : -1; // A = +1, B = -1

            row[r] += p;
            col[c] += p;

            if (r == c) dia += p;
            if (r + c == 2) anti += p;

            if (abs(row[r]) == 3 || abs(col[c]) == 3 ||
                abs(dia) == 3 || abs(anti) == 3) {
                return (p == 1) ? "A" : "B";
            }
        }

        return (moves.size() == 9) ? "Draw" : "Pending";
    }
};

// Optional main() for local testing
int main() {
    Solution sol;

    vector<vector<int>> moves = {
        {0,0}, {2,0}, {1,1}, {2,1}, {2,2}
    };

    cout << sol.tictactoe(moves) << endl; // Expected output: A
    return 0;
}

