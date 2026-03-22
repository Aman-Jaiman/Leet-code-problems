#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    bool searchKey(Node* head, int key) {
        while (head) {
            if (head->data == key) return true;
            head = head->next;
        }
        return false;
    }
};

// Helper to create list
Node* createList(vector<int> arr) {
    Node* dummy = new Node(0);
    Node* curr = dummy;

    for (int x : arr) {
        curr->next = new Node(x);
        curr = curr->next;
    }

    return dummy->next;
}

int main() {
    vector<int> arr = {10, 20, 30, 40};
    Node* head = createList(arr);

    Solution obj;
    int key = 30;

    if (obj.searchKey(head, key))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}