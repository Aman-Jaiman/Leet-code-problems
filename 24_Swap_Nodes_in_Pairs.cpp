/*
❓ Question: Swap Nodes in Pairs

Given a singly linked list, swap every two adjacent nodes and return its head.

⚠️ You must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed).

Example 1:
Input:  1->2->3->4
Output: 2->1->4->3

Example 2:
Input:  1
Output: 1

Example 3:
Input:  1->2->3
Output: 2->1->3
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* n): val(x), next(n) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // swap
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // move
            prev = first;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

// helper functions for testing
ListNode* make_list(const vector<int>& v) {
    ListNode* head = nullptr, *tail = nullptr;
    for (int x : v) {
        ListNode* node = new ListNode(x);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}
void print_list(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << '\n';
}

int main() {
    vector<int> vals = {1,2,3,4};
    ListNode* param_1 = make_list(vals);
    ListNode* ret = Solution().swapPairs(param_1);
    print_list(ret); // expected: 2->1->4->3
    return 0;
}
