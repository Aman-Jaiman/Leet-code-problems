/*
Problem: Linked List Cycle II

Given the head of a linked list, return the node where the cycle begins.
If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that
can be reached again by continuously following the next pointer.

Note:
- Do NOT modify the linked list.
- Use O(1) extra space.

LeetCode Problem: 142. Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) break;
        }

        // No cycle
        if (!fast || !fast->next) return nullptr;

        // Step 2: Find cycle start
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // Cycle starting node
    }
};

int main() {
    // Create linked list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create cycle: -4 -> 2
    head->next->next->next->next = head->next;

    Solution sol;
    ListNode* cycleNode = sol.detectCycle(head);

    if (cycleNode)
        cout << "Cycle starts at node with value: " << cycleNode->val << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}
