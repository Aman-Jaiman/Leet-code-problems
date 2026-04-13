#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        // constructor
    }

    // Push element to the back of queue
    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element
        s1.push(x);

        // Move everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Removes the element from front of queue
    int pop() {
        int val = s1.top();
        s1.pop();
        return val;
    }

    // Get the front element
    int peek() {
        return s1.top();
    }

    // Check if queue is empty
    bool empty() {
        return s1.empty();
    }
};

// Driver code (for testing)
int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peek() << endl;  // 10
    cout << "Pop: " << q.pop() << endl;     // 10
    cout << "Front: " << q.peek() << endl;  // 20
    cout << "Empty: " << q.empty() << endl; // 0 (false)

    return 0;
}
