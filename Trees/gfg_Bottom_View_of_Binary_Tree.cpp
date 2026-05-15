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
        left = right = nullptr;
    }
};

class Solution {
public:

    vector<int> bottomView(Node *root) {

        vector<int> ans;

        // edge case
        if(!root) return ans;

        // column -> latest node value
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

            // overwrite value for bottom view
            // lower levels come later in BFS
            mp[col] = node->data;

            // left child -> col-1
            if(node->left) {
                q.push({node->left,col-1});
            }

            // right child -> col+1
            if(node->right) {
                q.push({node->right,col+1});
            }
        }

        // map gives columns in sorted order
        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {

    /*
              20
             /  \
            8    22
           / \     \
          5   3     25
             / \
            10 14
    */

    Node* root = new Node(20);

    root->left = new Node(8);
    root->right = new Node(22);

    root->left->left = new Node(5);
    root->left->right = new Node(3);

    root->right->right = new Node(25);

    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Solution obj;

    vector<int> ans = obj.bottomView(root);

    cout << "Bottom View: ";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}