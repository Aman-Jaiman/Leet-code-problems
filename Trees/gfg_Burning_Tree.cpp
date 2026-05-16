#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:

    int minTime(Node* root, int target) {

        // child -> parent mapping
        unordered_map<Node*, Node*> parent;

        Node* start = nullptr;

        queue<Node*> q;

        q.push(root);

        // BFS to create parent mapping
        // and find target node
        while(!q.empty()) {

            Node* node = q.front();
            q.pop();

            // target node found
            if(node->data == target) {
                start = node;
            }

            // left child
            if(node->left) {

                parent[node->left] = node;
                q.push(node->left);
            }

            // right child
            if(node->right) {

                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // BFS for burning tree
        unordered_map<Node*, bool> vis;

        q.push(start);

        vis[start] = true;

        int time = 0;

        while(!q.empty()) {

            int size = q.size();

            bool burned = false;

            for(int i=0;i<size;i++) {

                Node* node = q.front();
                q.pop();

                // left child
                if(node->left &&
                   !vis[node->left]) {

                    vis[node->left] = true;
                    q.push(node->left);

                    burned = true;
                }

                // right child
                if(node->right &&
                   !vis[node->right]) {

                    vis[node->right] = true;
                    q.push(node->right);

                    burned = true;
                }

                // parent node
                if(parent[node] &&
                   !vis[parent[node]]) {

                    vis[parent[node]] = true;
                    q.push(parent[node]);

                    burned = true;
                }
            }

            // increase time only if
            // some new node burned
            if(burned)
                time++;
        }

        return time;
    }
};

int main() {

    /*
               1
             /   \
            2     3
           / \   / \
          4   5 6   7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;

    int target = 5;

    int ans = obj.minTime(root, target);

    cout << "Minimum Time to Burn Tree: "
         << ans << endl;

    return 0;
}