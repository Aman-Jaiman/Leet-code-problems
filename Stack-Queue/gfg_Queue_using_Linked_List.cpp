#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {

private:
    Node* front;
    Node* rear;
    int len;

public:

    myQueue() {
        front = nullptr;
        rear = nullptr;
        len = 0;
    }

    bool isEmpty() {
        return len == 0;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);

        if(isEmpty()){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }

        len++;
    }

    void dequeue() {
        if(isEmpty()) return;

        Node* temp = front;
        front = front->next;

        delete temp;
        len--;

        if(front == nullptr)
            rear = nullptr;
    }

    int getFront() {
        if(isEmpty()) return -1;
        return front->data;
    }

    int size() {
        return len;
    }
};