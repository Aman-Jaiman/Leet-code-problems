#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smaller(vector<vector<int>>& mat, int mid) {
        int count = 0;
        for(int i = 0; i < mat.size(); i++) {
            count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }
        return count;
    }

    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        int ele = (n * m) / 2;

        int low = 1;
        int high = 1e9;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int equlEle = smaller(mat, mid);

            if(equlEle > ele) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {

    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    Solution obj;

    cout << "Median: " << obj.median(mat) << endl;

    return 0;
}