#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int st = 0;
        int end = m - 1;
        
        while(st <= end) {
            
            int col = st + (end - st) / 2;
            
            int maxRow = 0;
            
            // find max element in this column
            for(int i = 0; i < n; i++) {
                if(mat[i][col] > mat[maxRow][col]) {
                    maxRow = i;
                }
            }
            
            int left = (col - 1 >= 0) ? mat[maxRow][col - 1] : -1;
            int right = (col + 1 < m) ? mat[maxRow][col + 1] : -1;
            
            int mid = mat[maxRow][col];
            
            if(mid > left && mid > right) {
                return {maxRow, col};
            }
            else if(left > mid) {
                end = col - 1;
            }
            else {
                st = col + 1;
            }
        }
        
        return {-1, -1};
    }
};