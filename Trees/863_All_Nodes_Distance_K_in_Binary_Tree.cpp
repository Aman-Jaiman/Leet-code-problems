#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for Binary Tree Node
struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    vector<int> distanceK(TreeNode* root,
                          TreeNode* target,
                          int k) {

        // child -> parent mapping
        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> q;

        q.push(root);

        // Build parent mapping
        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if(node->left) {

                parent[node->left] = node;
                q.push(node->left);
            }

            if(node->right) {

                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // BFS from target node
        unordered_map<TreeNode*, bool> vis;

        q.push(target);

        vis[target] = true;

        int distance = 0;

        while(!q.empty()) {

            int size = q.size();

            // reached distance k
            if(distance == k)
                break;

            distance++;

            for(int i=0;i<size;i++) {

                TreeNode* node = q.front();
                q.pop();

                // left child
                if(node->left &&
                   !vis[node->left]) {

                    vis[node->left] = true;
                    q.push(node->left);
                }

                // right child
                if(node->right &&
                   !vis[node->right]) {

                    vis[node->right] = true;
                    q.push(node->right);
                }

                // parent node
                if(parent[node] &&
                   !vis[parent[node]]) {

                    vis[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }

        vector<int> ans;

        // remaining queue nodes are at distance k
        while(!q.empty()) {

            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};

int main() {

    /*
                3
              /   \
             5     1
            / \   / \
           6   2 0   8
              / \
             7   4
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution obj;

    TreeNode* target = root->left; // node 5

    int k = 2;

    vector<int> ans =
        obj.distanceK(root, target, k);

    cout << "Nodes at distance "
         << k << " : ";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}