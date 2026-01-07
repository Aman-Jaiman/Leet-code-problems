#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Merge function to merge two sorted halves and count inversions
    int merge(vector<int>& arr, int st, int mid, int end) {
        vector<int> temp;
        int i = st;
        int j = mid + 1;
        int invCount = 0;

        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
                invCount += (mid - i + 1); // count inversions
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= end) {
            temp.push_back(arr[j]);
            j++;
        }

        // Copy back to original array
        for (int idx = 0; idx < temp.size(); idx++) {
            arr[st + idx] = temp[idx];
        }

        return invCount;
    }

    // Merge sort function
    int mergeSort(vector<int>& arr, int st, int end) {
        if (st >= end) return 0;

        int mid = st + (end - st) / 2;
        int leftInv = mergeSort(arr, st, mid);
        int rightInv = mergeSort(arr, mid + 1, end);
        int mergeInv = merge(arr, st, mid, end);

        return leftInv + rightInv + mergeInv;
    }

    // Main function to count inversions
    int inversionCount(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {8, 4, 2, 1};

    cout << "Inversion Count: " << sol.inversionCount(arr) << endl;

    return 0;
}
