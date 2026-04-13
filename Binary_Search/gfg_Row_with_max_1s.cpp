#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();

        int maxRow = -1;
        int maxOnes = 0;

        for(int i = 0; i < n; i++) {
            int st = 0, end = m - 1;
            int firstOne = m;

            // Binary search for first 1
            while(st <= end) {
                int mid = st + (end - st) / 2;

                if(arr[i][mid] == 1) {
                    firstOne = mid;
                    end = mid - 1;
                }
                else {
                    st = mid + 1;
                }
            }

            int ones = m - firstOne;

            if(ones > maxOnes) {
                maxOnes = ones;
                maxRow = i;
            }
        }

        return maxRow;
    }
};

int main() {
    vector<vector<int>> arr = {
        {0,0,0,1},
        {0,1,1,1},
        {0,0,1,1},
        {0,0,0,0}
    };

    Solution obj;
    cout << "Row with max 1s: " << obj.rowWithMax1s(arr);

    return 0;
}