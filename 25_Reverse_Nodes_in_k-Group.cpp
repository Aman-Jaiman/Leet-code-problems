#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: check if there are at least k nodes
        ListNode* temp = head;
        int count = 0;
        while (count < k) {
            if (temp == nullptr) return head;
            temp = temp->next;
            count++;
        }

        // Step 2: reverse remaining list first
        ListNode* prev = reverseKGroup(temp, k);

        // Step 3: reverse current k nodes
        temp = head;
        count = 0;
        while (count < k) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }

        // prev is new head after reversal
        return prev;
    }
};
