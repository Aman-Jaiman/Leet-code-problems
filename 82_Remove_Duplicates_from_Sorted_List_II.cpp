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
    ListNode* deleteDuplicates(ListNode* head) {
        // dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            // if duplicate found
            if (curr->next && curr->val == curr->next->val) {
                int dupVal = curr->val;

                // skip all nodes with same value
                while (curr && curr->val == dupVal) {
                    curr = curr->next;
                }
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        ListNode* newHead = dummy->next;
        // delete dummy; // optional in competitive programming
        return newHead;
    }
};

// -------- Helper functions (for testing) --------
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating list: 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
    ListNode* head = new ListNode(1,
        new ListNode(2,
            new ListNode(3,
                new ListNode(3,
                    new ListNode(4,
                        new ListNode(4,
                            new ListNode(5)))))));

    cout << "Original List:\n";
    printList(head);

    Solution sol;
    ListNode* ans = sol.deleteDuplicates(head);

    cout << "After Removing Duplicates:\n";
    printList(ans);

    return 0;
}
