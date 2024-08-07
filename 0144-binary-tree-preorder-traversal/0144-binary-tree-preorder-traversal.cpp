/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
   void solve(TreeNode*root, vector<int>&vec){
        if(root==NULL){
           return ;
        }
        vec.push_back(root->val);
        if(root->left!=NULL){
            solve(root->left, vec);
        }
        if(root->right!=NULL){
            solve(root->right, vec);
        }

        return ;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;

        solve(root, ans);
        return ans;
    }
};