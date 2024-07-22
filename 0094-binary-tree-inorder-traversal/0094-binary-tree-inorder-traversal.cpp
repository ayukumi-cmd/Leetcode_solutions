
class Solution {
public:
   void solve(TreeNode*root, vector<int>&vec){
        if(root==NULL){
           return ;
        }

        if(root->left!=NULL){
            solve(root->left, vec);
        }

        vec.push_back(root->val);

        if(root->right!=NULL){
            solve(root->right, vec);
        }

        return ;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;

        solve(root, ans);
        return ans;
    }
};