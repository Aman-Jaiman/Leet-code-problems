#include <iostream>
#include <vector>
using namespace std;

class myStack {
public:
    vector<int> vec;
    int n;

    myStack(int n1) {
        n = n1;
    }

    bool isEmpty() {
        return vec.size() == 0;
    }

    bool isFull() {
        return vec.size() == n;
    }

    void push(int x) {
        if(vec.size() == n) {
            // cout << "Stack Overflow\n";
            return;
        }
        vec.push_back(x);
    }

    void pop() {
        if(vec.size() == 0) {
            // cout << "Stack Underflow\n";
            return;
        }
        vec.pop_back();
    }

    int peek() {
        if(vec.size() == 0) return -1;
        return vec[vec.size() - 1];
    }
};

int main() {

    myStack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.peek() << endl;

    st.pop();

    cout << "Top element after pop: " << st.peek() << endl;

    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}