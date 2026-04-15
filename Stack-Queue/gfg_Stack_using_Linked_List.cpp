#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class myStack {

private:
    Node* topNode;
    int sz;

public:

    myStack() {
        topNode = nullptr;
        sz = 0;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
        sz++;
    }

    void pop() {
        if(isEmpty()) return;

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        sz--;
    }

    int peek() {
        if(isEmpty()) return -1;
        return topNode->data;
    }

    int size() {
        return sz;
    }
};