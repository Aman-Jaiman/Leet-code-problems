#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        // constructor
    }

    // Push element onto stack
    void push(int x) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push new element into q1
        q1.push(x);

        // Move everything back to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Removes the element on top of the stack
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    // Get the top element
    int top() {
        return q1.front();
    }

    // Returns whether the stack is empty
    bool empty() {
        return q1.empty();
    }
};

// Driver code (for testing)
int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;   // 30
    cout << "Pop: " << st.pop() << endl;   // 30
    cout << "Top: " << st.top() << endl;   // 20
    cout << "Empty: " << st.empty() << endl; // 0 (false)

    return 0;
}
