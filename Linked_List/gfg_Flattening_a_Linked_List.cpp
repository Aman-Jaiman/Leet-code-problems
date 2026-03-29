#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
public:

    Node* merge(Node* a, Node* b){

        if(!a) return b;
        if(!b) return a;

        Node* result;

        if(a->data < b->data){
            result = a;
            result->bottom = merge(a->bottom, b);
        }
        else{
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        result->next = NULL;
        return result;
    }

    Node* flatten(Node* root){

        if(!root || !root->next)
            return root;

        root->next = flatten(root->next);

        root = merge(root, root->next);

        return root;
    }
};

void printList(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main(){

    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution obj;

    Node* result = obj.flatten(head);

    cout << "Flattened List:\n";
    printList(result);

    return 0;
}