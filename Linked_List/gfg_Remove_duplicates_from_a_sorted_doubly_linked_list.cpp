#include <iostream>
using namespace std;

/* Doubly Linked List Node */
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    Node* removeDuplicates(Node* head) {

        if(!head) return head;

        Node* curr = head;

        while(curr) {

            Node* temp = curr->next;

            // Skip duplicate nodes
            while(temp && temp->data == curr->data) {
                temp = temp->next;
            }

            curr->next = temp;

            if(temp)
                temp->prev = curr;

            curr = temp;
        }

        return head;
    }
};

/* Insert node at end */
void insert(Node*& head, int val) {

    Node* newNode = new Node(val);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

/* Print Doubly Linked List */
void printList(Node* head) {

    while(head) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    Node* head = NULL;

    insert(head,1);
    insert(head,2);
    insert(head,2);
    insert(head,3);
    insert(head,3);
    insert(head,4);

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    head = obj.removeDuplicates(head);

    cout << "After Removing Duplicates:\n";
    printList(head);

    return 0;
}