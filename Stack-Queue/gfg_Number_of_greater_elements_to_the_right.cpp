#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int> ans;

        for (int idx : indices) {
            int count = 0;

            for (int j = idx + 1; j < n; j++) {
                if (arr[j] > arr[idx]) {
                    count++;
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10};
    vector<int> indices = {0, 1, 2};

    Solution obj;
    vector<int> res = obj.count_NGE(arr, indices);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}





