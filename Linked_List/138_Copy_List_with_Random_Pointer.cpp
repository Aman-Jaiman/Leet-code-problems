/*
Problem: Copy List with Random Pointer

A linked list is given such that each node contains an additional
random pointer, which could point to any node in the list or null.

Return a deep copy of the list.

LeetCode Problem: 138. Copy List with Random Pointer
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;

        // Step 1: Create copy of each node (only next pointers)
        Node* newHead = new Node(head->val);
        mp[head] = newHead;

        Node* oldPtr = head->next;
        Node* newPtr = newHead;

        while (oldPtr != nullptr) {
            Node* copyNode = new Node(oldPtr->val);
            mp[oldPtr] = copyNode;
            newPtr->next = copyNode;

            newPtr = newPtr->next;
            oldPtr = oldPtr->next;
        }

        // Step 2: Assign random pointers
        oldPtr = head;
        newPtr = newHead;

        while (oldPtr != nullptr) {
            newPtr->random = mp[oldPtr->random]; // works even if random is NULL
            oldPtr = oldPtr->next;
            newPtr = newPtr->next;
        }

        return newHead;
    }
};

int main() {
    /*
        Example:
        Node values: 7 -> 13 -> 11 -> 10 -> 1
        Random pointers:
        7  -> NULL
        13 -> 7
        11 -> 1
        10 -> 11
        1  -> 7
    */

    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    Solution sol;
    Node* copiedHead = sol.copyRandomList(n1);

    // Print copied list
    Node* temp = copiedHead;
    cout << "Copied list (val, random->val):\n";
    while (temp != nullptr) {
        cout << temp->val << " , ";
        if (temp->random)
            cout << temp->random->val << endl;
        else
            cout << "NULL" << endl;
        temp = temp->next;
    }

    return 0;
}
