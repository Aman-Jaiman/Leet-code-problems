#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;

        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }
        return row;
    }
};

int main() {
    Solution sol;

    int rowIndex = 4;
    vector<int> result = sol.getRow(rowIndex);

    cout << "Pascal Row " << rowIndex << ": ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
