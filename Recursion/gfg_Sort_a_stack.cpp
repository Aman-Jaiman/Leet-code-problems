#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:

    void insertSort(stack<int>& st, int temp){
        // base condition
        if(st.empty() || st.top() <= temp){
            st.push(temp);
            return;
        }

        int curr = st.top();
        st.pop();

        insertSort(st, temp);

        st.push(curr);
    }

    void sortStack(stack<int> &st){
        if(st.empty()) return;

        int temp = st.top();
        st.pop();

        sortStack(st);

        insertSort(st, temp);
    }
};

int main(){

    stack<int> st;

    st.push(30);
    st.push(10);
    st.push(50);
    st.push(20);

    Solution obj;
    obj.sortStack(st);

    cout << "Sorted Stack (Top to Bottom): ";

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}