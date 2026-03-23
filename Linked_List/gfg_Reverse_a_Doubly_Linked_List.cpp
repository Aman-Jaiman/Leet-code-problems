#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class Solution {
public:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* temp = nullptr;

        while (curr) {
            // Swap next and prev
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            // Move to next node (which is prev now)
            curr = curr->prev;
        }

        // Update head
        if (temp)
            head = temp->prev;

        return head;
    }
};
