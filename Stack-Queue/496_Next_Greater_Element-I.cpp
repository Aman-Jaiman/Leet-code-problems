#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> m;
        vector<int> ans;

        for(int i = nums2.size()-1; i >= 0; i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }

            if(st.empty()){
                m[nums2[i]] = -1;
            }
            else{
                m[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(m[nums1[i]]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> result = obj.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for(int x : result){
        cout << x << " ";
    }

    cout << endl;

    return 0;
}