/*
Problem: Flatten a Multilevel Doubly Linked List

You are given a doubly linked list where each node has:
- val
- prev
- next
- child

The child pointer may point to another doubly linked list.
Flatten the list so that all nodes appear in a single-level
doubly linked list, and all child pointers are set to NULL.

LeetCode Problem: 430
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return NULL;

        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {

                Node* next = curr->next;

                // Flatten child list
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                // Move to tail of flattened child
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                // Attach original next
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};

int main() {
    /*
        Example:

        1 - 2 - 3 - 4 - 5
                |
                6 - 7

        Output:
        1 - 2 - 3 - 6 - 7 - 4 - 5
    */

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);

    // Main list
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;

    // Child list
    n3->child = n6;
    n6->next = n7; n7->prev = n6;

    Solution sol;
    Node* head = sol.flatten(n1);

    cout << "Flattened list: ";
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
