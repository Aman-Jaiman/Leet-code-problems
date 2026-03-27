#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* addOne(Node* head) {

        Node* lastNonNine = NULL;
        Node* curr = head;

        // Find last node which is not 9
        while (curr) {
            if (curr->data != 9)
                lastNonNine = curr;
            curr = curr->next;
        }

        // If all digits are 9
        if (lastNonNine == NULL) {
            Node* newHead = new Node(1);
            newHead->next = head;
            head = newHead;
            curr = head->next;
        } 
        else {
            lastNonNine->data += 1;
            curr = lastNonNine->next;
        }

        // Set remaining digits to 0
        while (curr) {
            curr->data = 0;
            curr = curr->next;
        }

        return head;
    }
};