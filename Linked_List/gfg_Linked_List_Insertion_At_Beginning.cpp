#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node *insertAtFront(Node *head, int x) {
        // Code here
        Node* newNode =new Node(x);
        newNode->next=head;
        
        head=newNode;
        
        return head;
        
    }
};