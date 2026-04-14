#include <vector>
using namespace std;

class myQueue {
public:
    vector<int> q;
    int front, rear, n;

    myQueue(int n1) {
        n = n1;
        q.resize(n);
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % n == front;
    }

    void enqueue(int x) {
        if(isFull()) return;

        if(isEmpty()) {
            front = rear = 0;
        } 
        else {
            rear = (rear + 1) % n;
        }

        q[rear] = x;
    }

    void dequeue() {
        if(isEmpty()) return;

        if(front == rear) {
            front = rear = -1;
        } 
        else {
            front = (front + 1) % n;
        }
    }

    int getFront() {
        if(isEmpty()) return -1;
        return q[front];
    }

    int getRear() {
        if(isEmpty()) return -1;
        return q[rear];
    }
};