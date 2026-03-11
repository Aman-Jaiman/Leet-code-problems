/*
    Question: Remove N-th Node From End of List

    Given the head of a linked list, remove the n-th node from the end 
    of the list and return its head.

    Example 1:
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]

    Example 2:
    Input: head = [1], n = 1
    Output: []

    Example 3:
    Input: head = [1,2], n = 1
    Output: [1]
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node for easier deletion
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Step 1: Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Step 2: Move both pointers until fast reaches the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 3: Delete the nth node from end
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;

        delete toDelete; // Free memory

        return dummy.next;
    }
};

// Helper function to print list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code (for testing)
int main() {
    // Create list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution s;
    int n = 2;
    head = s.removeNthFromEnd(head, n);

    cout << "After removing " << n << "th node from end: ";
    printList(head);

    return 0;
}
