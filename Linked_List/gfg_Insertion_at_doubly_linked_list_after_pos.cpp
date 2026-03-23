#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};

class Solution {
public:
    Node* insertAfterPos(Node* head, int p, int x) {
        if (!head) return new Node(x);

        Node* curr = head;

        // Move to p-th node
        for (int i = 0; i < p && curr; i++) {
            curr = curr->next;
        }

        // Invalid position
        if (!curr) return head;

        Node* newNode = new Node(x);

        // Insert after curr
        newNode->next = curr->next;
        newNode->prev = curr;

        if (curr->next)
            curr->next->prev = newNode;

        curr->next = newNode;

        return head;
    }
};
