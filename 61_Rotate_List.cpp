#include <iostream>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length
        ListNode* curr = head;
        int n = 1;
        while (curr->next) {
            curr = curr->next;
            n++;
        }

        // Step 2: Optimize k
        k = k % n;
        if (k == 0) return head;

        // Step 3: Find new tail (n - k - 1)
        curr = head;
        for (int i = 0; i < n - k - 1; i++) {
            curr = curr->next;
        }

        // Step 4: Rotate
        ListNode* newHead = curr->next;
        curr->next = nullptr;

        ListNode* tail = newHead;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head;

        return newHead;
    }
};

// ----------- Optional: Testing Code -----------
int main() {
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution sol;
    head = sol.rotateRight(head, k);

    // Print rotated list
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
