/*
====================================================
Merge Sort - Complete C++ Program
====================================================

Problem:
--------
Given an array of integers, sort the array using
Merge Sort (Divide and Conquer algorithm).

Approach:
---------
1. Divide the array into two halves
2. Recursively sort both halves
3. Merge the sorted halves

Time Complexity:
----------------
Best / Average / Worst : O(n log n)

Space Complexity:
-----------------
O(n) (temporary array)

Stable Sort: YES
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Merge two sorted subarrays arr[l..mid] and arr[mid+1..r]
    void merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> temp;
        int i = l;
        int j = mid + 1;

        // Compare and merge
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        // Remaining elements of left half
        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        // Remaining elements of right half
        while (j <= r) {
            temp.push_back(arr[j]);
            j++;
        }

        // Copy back to original array
        for (int k = 0; k < temp.size(); k++) {
            arr[l + k] = temp[k];
        }
    }

    // Recursive merge sort
    void mergeSort(vector<int>& arr, int l, int r) {
        // Base case
        if (l >= r) return;

        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);       // Left half
        mergeSort(arr, mid + 1, r);   // Right half
        merge(arr, l, mid, r);        // Merge
    }
};

int main() {
    Solution sol;

    vector<int> arr = {5, 2, 4, 1, 3};

    cout << "Original Array:\n";
    for (int x : arr) cout << x << " ";
    cout << endl;

    sol.mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array:\n";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
