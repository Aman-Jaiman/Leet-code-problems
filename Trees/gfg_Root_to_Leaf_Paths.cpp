#include <iostream>
#include <vector>

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

    vector<vector<int>> ans;

    // DFS function
    void dfs(Node* root, vector<int> vec) {

        // add current node
        vec.push_back(root->data);

        // leaf node
        if(!root->left && !root->right) {

            ans.push_back(vec);
            return;
        }

        // go left
        if(root->left) {
            dfs(root->left, vec);
        }

        // go right
        if(root->right) {
            dfs(root->right, vec);
        }
    }

    vector<vector<int>> Paths(Node* root) {

        vector<int> vec;

        dfs(root, vec);

        return ans;
    }
};

int main() {

    /*
              1
            /   \
           2     3
          / \     \
         4   5     6
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    Solution obj;

    vector<vector<int>> paths = obj.Paths(root);

    cout << "Root to Leaf Paths:\n";

    for(auto path : paths) {

        for(int x : path) {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}