#include <iostream>
using namespace std;

/* Doubly Linked List Node */
struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    void deleteAllOccurOfX(Node** head_ref, int x){

        Node* curr = *head_ref;

        while(curr){

            if(curr->data == x){

                Node* nextNode = curr->next;

                // deleting head node
                if(curr->prev == NULL){
                    *head_ref = curr->next;

                    if(*head_ref)
                        (*head_ref)->prev = NULL;
                }
                else{
                    curr->prev->next = curr->next;

                    if(curr->next)
                        curr->next->prev = curr->prev;
                }

                delete curr;
                curr = nextNode;
            }
            else{
                curr = curr->next;
            }
        }
    }
};

/* Insert at end */
void insert(Node*& head,int val){

    Node* newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

/* Print List */
void printList(Node* head){

    while(head){
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main(){

    Node* head = NULL;

    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,2);
    insert(head,4);

    cout<<"Original List:\n";
    printList(head);

    Solution obj;
    obj.deleteAllOccurOfX(&head,2);

    cout<<"After Deleting 2:\n";
    printList(head);

    return 0;
}