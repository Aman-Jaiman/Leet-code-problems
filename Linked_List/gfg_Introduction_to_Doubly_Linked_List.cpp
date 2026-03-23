#include <bits/stdc++.h>
using namespace std;

/* Node structure */
class Node {
public:
    Node* prev;
    int data;
    Node* next;

    Node(int value) {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution {
public:
    Node* constructDLL(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return NULL;

        // Create head
        Node* head = new Node(arr[0]);
        Node* curr = head;

        // Create rest of nodes
        for (int i = 1; i < n; i++) {
            Node* newNode = new Node(arr[i]);

            curr->next = newNode;
            newNode->prev = curr;

            curr = newNode; // move forward
        }

        return head;
    }
};
