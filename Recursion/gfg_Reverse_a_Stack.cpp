#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:

    void insertStack(stack<int>& st, int temp){
        if(st.empty()){
            st.push(temp);
            return;
        }

        int curr = st.top();
        st.pop();

        insertStack(st, temp);

        st.push(curr);
    }

    void reverseStack(stack<int> &st){
        if(st.empty()) return;

        int temp = st.top();
        st.pop();

        reverseStack(st);

        insertStack(st, temp);
    }
};

int main() {

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    Solution obj;
    obj.reverseStack(st);

    cout << "Reversed Stack (Top to Bottom): ";

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}