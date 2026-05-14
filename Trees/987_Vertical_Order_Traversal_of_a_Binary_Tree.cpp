#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Definition for binary tree node
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

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // column -> row -> sorted node values
        map<int, map<int, multiset<int>>> mp;

        // Queue stores:
        // {node,{column,row}}
        queue<pair<TreeNode*,pair<int,int>>> q;

        // root at (0,0)
        q.push({root,{0,0}});

        while(!q.empty()){

            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;

            int x = p.second.first;   // column
            int y = p.second.second;  // row

            // insert value at position
            mp[x][y].insert(node->val);

            // left child -> col-1,row+1
            if(node->left)
                q.push({node->left,{x-1,y+1}});

            // right child -> col+1,row+1
            if(node->right)
                q.push({node->right,{x+1,y+1}});
        }

        vector<vector<int>> ans;

        // traverse all columns
        for(auto a : mp){

            vector<int> col;

            // traverse rows
            for(auto b : a.second){

                // add multiset values
                col.insert(
                    col.end(),
                    b.second.begin(),
                    b.second.end()
                );
            }

            ans.push_back(col);
        }

        return ans;
    }
};
