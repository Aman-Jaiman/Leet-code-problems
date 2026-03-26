#include <bits/stdc++.h>
using namespace std;

// Node definition
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Solution class
class Solution {
public:
    Node* segregate(Node* head) {
        if(!head || !head->next) return head;

        Node zeroDummy(0), oneDummy(0), twoDummy(0);
        Node *zero = &zeroDummy, *one = &oneDummy, *two = &twoDummy;

        Node* curr = head;

        while(curr){
            if(curr->data == 0){
                zero->next = curr;
                zero = zero->next;
            }
            else if(curr->data == 1){
                one->next = curr;
                one = one->next;
            }
            else{
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Connect lists properly
        zero->next = (oneDummy.next) ? oneDummy.next : twoDummy.next;
        one->next = twoDummy.next;
        two->next = NULL;

        return zeroDummy.next;
    }
};

// Insert at end
Node* insert(Node* head, int val){
    Node* newNode = new Node(val);

    if(!head) return newNode;

    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Print list
void printList(Node* head){
    while(head){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    // Example input: 1 -> 2 -> 0 -> 1 -> 2 -> 0
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 0);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 0);

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    head = obj.segregate(head);

    cout << "Segregated List:\n";
    printList(head);

    return 0;
}