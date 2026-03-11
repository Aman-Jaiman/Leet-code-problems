/*
LeetCode 206. Reverse Linked List
--------------------------------
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example:
Input:  1 -> 2 -> 3 -> 4 -> 5 -> NULL
Output: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Iterative approach to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next; // save next
            curr->next = prev;              // reverse pointer
            prev = curr;                    // move prev
            curr = nextNode;                // move curr
        }
        return prev; // new head
    }
};

// Helper function to print list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example test case
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* reversed = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(reversed);

    return 0;
}
