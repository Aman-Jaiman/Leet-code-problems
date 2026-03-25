#include <iostream>
using namespace std;

// Definition of Node
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
    int lengthOfLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Count loop length
                int count = 1;
                Node* temp = slow->next;

                while (temp != slow) {
                    count++;
                    temp = temp->next;
                }

                return count;
            }
        }

        return 0; // No loop
    }
};

// Helper to create loop (for testing)
void createLoop(Node* head, int pos) {
    if (pos == 0) return;

    Node* loopNode = head;
    for (int i = 1; i < pos; i++) {
        loopNode = loopNode->next;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = loopNode;
}

// Main function
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    createLoop(head, 2); // loop starts at node 2

    Solution obj;
    cout << "Length of loop: " << obj.lengthOfLoop(head) << endl;

    return 0;
}