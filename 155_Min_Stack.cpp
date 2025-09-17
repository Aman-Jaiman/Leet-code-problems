// 155. Min Stack
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
// Implement the MinStack class:
// - MinStack() initializes the stack object.
// - void push(int val) pushes the element val onto the stack.
// - void pop() removes the element on the top of the stack.
// - int top() gets the top element of the stack.
// - int getMin() retrieves the minimum element in the stack.
//
// Example:
// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]
// Output
// [null,null,null,null,-3,null,0,-2]

#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> st;     // normal stack
    stack<int> minSt;  // keeps track of minimums

public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if (st.empty()) return;
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        if (st.empty()) return -1; // or throw exception
        return st.top();
    }
    
    int getMin() {
        if (minSt.empty()) return -1; // or throw exception
        return minSt.top();
    }
};

int main() {
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout << "getMin: " << obj.getMin() << endl; // -3
    obj.pop();
    cout << "top: " << obj.top() << endl;       // 0
    cout << "getMin: " << obj.getMin() << endl; // -2
    return 0;
}
