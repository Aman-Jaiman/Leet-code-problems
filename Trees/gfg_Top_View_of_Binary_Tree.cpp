#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:

    // Function to return top view of binary tree
    vector<int> topView(Node *root) {

        vector<int> ans;

        // edge case
        if(!root) return ans;

        // column -> first node at that column
        map<int,int> mp;

        // queue stores:
        // {node,column}
        queue<pair<Node*,int>> q;

        // root at column 0
        q.push({root,0});

        // BFS traversal
        while(!q.empty()) {

            Node* node = q.front().first;
            int col = q.front().second;

            q.pop();

            // store first node of each column
            if(mp.find(col) == mp.end()) {
                mp[col] = node->data;
            }

            // left child -> col-1
            if(node->left) {
                q.push({node->left,col-1});
            }

            // right child -> col+1
            if(node->right) {
                q.push({node->right,col+1});
            }
        }

        // map automatically sorted by column
        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {

    /*
              1
            /   \
           2     3
            \
             4
              \
               5
                \
                 6
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);

    root->left->right->right = new Node(5);

    root->left->right->right->right = new Node(6);

    Solution obj;

    vector<int> ans = obj.topView(root);

    cout << "Top View: ";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}