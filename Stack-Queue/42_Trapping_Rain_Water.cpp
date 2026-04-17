// Trapping Rain Water - Two Pointer Approach
#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        unordered_map<int,int>m;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=height[i]){
                st.pop();
            }
            if(st.empty()){
                m[i]=0;
                st.push(height[i]);
            }
            else{
                m[i]=st.top();
            }
            // st.push(height[i]);
        }
        int left=height[0];
        for(int i=0;i<n;i++){
            int right=m[i];
            int ct=min(left,right)-height[i];
            if(ct>0){
                ans+=ct;
            }
            left=max(height[i],left);
        }
        return ans;
    }
};
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int ans = 0;

        while(left < right) {

            if(height[left] < height[right]) {

                if(height[left] >= leftMax)
                    leftMax = height[left];
                else
                    ans += leftMax - height[left];

                left++;
            }
            else {

                if(height[right] >= rightMax)
                    rightMax = height[right];
                else
                    ans += rightMax - height[right];

                right--;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> height = {4,2,0,3,2,5};

    cout << "Water trapped: " << obj.trap(height) << endl;

    return 0;
}