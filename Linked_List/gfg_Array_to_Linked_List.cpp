#include <bits/stdc++.h>
using namespace std;

// Definition of Node
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
public:
    Node* arrayToList(vector<int>& arr) {
        Node* dummy = new Node(0);  // dummy node
        Node* curr = dummy;

        for (int x : arr) {
            curr->next = new Node(x);
            curr = curr->next;
        }

        return dummy->next;
    }
};

// Helper function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    Solution obj;
    Node* head = obj.arrayToList(arr);

    printList(head);

    return 0;
}