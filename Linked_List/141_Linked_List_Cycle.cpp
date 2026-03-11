/*
Problem: Linked List Cycle

Given the head of a singly linked list,
determine if the linked list has a cycle in it.

A cycle exists if some node in the list can be
reached again by continuously following the next pointer.

LeetCode Problem: 141. Linked List Cycle
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; // cycle detected
            }
        }
        return false; // no cycle
    }
};

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Create a cycle: 4 -> 2
    head->next->next->next->next = head->next;

    Solution sol;
    cout << (sol.hasCycle(head) ? "Cycle detected" : "No cycle") << endl;

    return 0;
}
