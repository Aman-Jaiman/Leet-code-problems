#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(l1 && l2){
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        temp->next = (l1 ? l1 : l2);
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        mid->next = NULL;

        ListNode* left = sortList(head);
        right = sortList(right);

        return merge(left, right);
    }
};

// Helper: Insert node at end
ListNode* insert(ListNode* head, int val){
    ListNode* newNode = new ListNode(val);

    if(!head) return newNode;

    ListNode* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Helper: Print list
void printList(ListNode* head){
    while(head){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = NULL;

    // Example input: 4 -> 2 -> 1 -> 3
    head = insert(head, 4);
    head = insert(head, 2);
    head = insert(head, 1);
    head = insert(head, 3);

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    head = obj.sortList(head);

    cout << "Sorted List:\n";
    printList(head);

    return 0;
}