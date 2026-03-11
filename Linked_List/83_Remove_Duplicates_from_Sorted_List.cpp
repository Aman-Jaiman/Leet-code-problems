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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr) {
            if (prev->val != curr->val) {
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }

        // very important: cut off remaining duplicates
        prev->next = nullptr;

        return head;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Create linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    cout << "Original List:\n";
    printList(head);

    Solution sol;
    head = sol.deleteDuplicates(head);

    cout << "After Removing Duplicates:\n";
    printList(head);

    return 0;
}
