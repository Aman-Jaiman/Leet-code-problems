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
    int getCount(Node* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
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
    vector<int> arr = {1, 2, 3, 4, 5};

    Node* head = createList(arr);

    Solution obj;
    cout << obj.getCount(head) << endl;

    return 0;
}