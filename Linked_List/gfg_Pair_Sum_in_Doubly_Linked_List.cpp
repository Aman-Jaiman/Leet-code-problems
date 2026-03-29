#include <iostream>
#include <vector>
using namespace std;

/* Doubly Linked List Node */
struct Node {
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
    vector<pair<int,int>> findPairsWithGivenSum(Node *head, int target){

        vector<pair<int,int>> ans;

        if(!head || !head->next)
            return ans;

        Node* left = head;
        Node* right = head;

        // move right pointer to last node
        while(right->next)
            right = right->next;

        while(left && right && left != right && right->next != left){

            int sum = left->data + right->data;

            if(sum == target){
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if(sum < target){
                left = left->next;
            }
            else{
                right = right->prev;
            }
        }

        return ans;
    }
};

/* Insert node at end */
void insert(Node*& head, int val){

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

/* Print Doubly Linked List */
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
    insert(head,4);
    insert(head,5);

    cout<<"Doubly Linked List:\n";
    printList(head);

    int target = 5;

    Solution obj;
    vector<pair<int,int>> result = obj.findPairsWithGivenSum(head,target);

    cout<<"Pairs with sum "<<target<<":\n";

    for(auto p : result){
        cout<<"("<<p.first<<","<<p.second<<") ";
    }

    cout<<endl;

    return 0;
}