#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low<high){
            int pvtidx =partition(arr,low, high);
            quickSort(arr,low,pvtidx-1);//Left part
            quickSort(arr,pvtidx+1,high);//right part
        }
            
    }

    
  public:
    int partition(vector<int>& arr, int low, int high) {
        
        // code here
        int pvit = arr[high];
        int idx =low-1;
        
        for(int j=low;j<high;j++){
            if(arr[j]<=pvit){
                idx++;
                swap(arr[j],arr[idx]);
            }
        }    
        idx++;
        swap(arr[high],arr[idx]);
        return idx;
        
    }
  

};

int main() {
    Solution sol;

    vector<int> arr = {5, 2, 4, 1, 3};

    cout << "Original Array:\n";
    for (int x : arr) cout << x << " ";
    cout << endl;

    sol.quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array:\n";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}