/*
====================================================
Rat in a Maze Problem (Backtracking)
====================================================

A rat starts from (0,0) and wants to reach (n-1,n-1).
The rat can move in four directions:
D = Down, U = Up, L = Left, R = Right

Cell value:
1 -> open path
0 -> blocked path

Return all possible paths in lexicographical order.
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& maze, int row, int col,
                string path, vector<string>& ans) {

        int n = maze.size();

        // Boundary + blocked + visited check
        if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] != 1) {
            return;
        }

        // Destination reached
        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

        // Mark visited
        maze[row][col] = -1;

        // Move in all 4 directions
        helper(maze, row + 1, col, path + "D", ans); // Down
        helper(maze, row - 1, col, path + "U", ans); // Up
        helper(maze, row, col - 1, path + "L", ans); // Left
        helper(maze, row, col + 1, path + "R", ans); // Right

        // Unmark (backtrack)
        maze[row][col] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;

        int n = maze.size();
        if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        helper(maze, 0, 0, "", ans);

        sort(ans.begin(), ans.end()); // optional (GFG expects sorted)
        return ans;
    }
};
