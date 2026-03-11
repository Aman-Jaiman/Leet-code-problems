/*
LeetCode 2965. Find Missing and Repeated Values

Problem:
You are given an n x n integer matrix grid where each integer is in the range [1, n^2].
Each number from 1 to n^2 should appear exactly once in the matrix.
However, one number is missing, and one number is repeated.
Return [repeated, missing].

Example:
Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation:
- The number 2 is repeated.
- The number 4 is missing.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;                   // To store [repeated, missing]
        unordered_set<int> s;              // To keep track of numbers we have seen
        int n = grid.size();               // Grid size (n x n)
        int repeated = -1, missing = -1;
        long long expectedSum = 0;         // Expected sum of numbers 1..n^2
        long long actualSum = 0;           // Actual sum of numbers in grid

        // Traverse the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                actualSum += val;

                // If already present → this is the repeated value
                if (s.find(val) != s.end()) {
                    repeated = val;
                }
                s.insert(val);
            }
        }

        // Expected sum of 1..n^2 → formula: (N * (N+1)) / 2
        int totalNums = n * n;
        expectedSum = (1LL * totalNums * (totalNums + 1)) / 2;

        // Find the missing number:
        // expectedSum = actualSum - repeated + missing
        // => missing = expectedSum + repeated - actualSum
        missing = expectedSum + repeated - actualSum;

        ans.push_back(repeated);
        ans.push_back(missing);

        return ans;
    }
};

// ---------- Driver Code (for local testing) ----------
int main() {
    Solution sol;

    vector<vector<int>> grid1 = {{1, 3}, {2, 2}};
    vector<int> res1 = sol.findMissingAndRepeatedValues(grid1);
    cout << "Repeated: " << res1[0] << ", Missing: " << res1[1] << endl;
    // Expected: [2,4]

    vector<vector<int>> grid2 = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> res2 = sol.findMissingAndRepeatedValues(grid2);
    cout << "Repeated: " << res2[0] << ", Missing: " << res2[1] << endl;
    // Expected: [9,5]

    return 0;
}
