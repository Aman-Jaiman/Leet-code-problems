// File: 21. Merge Two Sorted Lists.cpp
//
// Problem Statement:
// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by
// splicing together the nodes of the first two lists.
// Return the head of the merged linked list.
//
// Example:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
//
// Constraints:
// - The number of nodes in both lists is in the range [0, 50].
// - -100 <= Node.val <= 100
// - Both list1 and list2 are sorted in non-decreasing order.

#include <iostream>
#include <vector>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If any one list is empty, return the other
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head = nullptr; // final merged list ka head
        ListNode* tail = nullptr; // current last node (tail)

        // Pehla node choose karo (head + tail set karo)
        if (list1->val <= list2->val) {
            head = tail = list1;
            list1 = list1->next;
        } else {
            head = tail = list2;
            list2 = list2->next;
        }

        // ✅ Simple merging loop (B part)
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;   // list1 ka node attach
                list1 = list1->next;  // list1 aage badhao
            } else {
                tail->next = list2;   // list2 ka node attach
                list2 = list2->next;  // list2 aage badhao
            }
            tail = tail->next;        // tail ko naya last node bana do
        }

        // Jo list bachi hai use seedha attach kar do
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return head; // merged list ka starting node
    }
};

// --------- Helper functions for local testing (not needed on LeetCode) ---------

// Vector se linked list banao (sorted input assume)
ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Linked list print karo
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    // Example: list1 = [1,2,4], list2 = [1,3,4]
    vector<int> v1 = {1, 2, 4};
    vector<int> v2 = {1, 3, 4};

    ListNode* list1 = buildList(v1);
    ListNode* list2 = buildList(v2);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    cout << "Merged: ";
    printList(merged);

    return 0;
}
