



class Solution {
public:
   void solve(TreeNode*root, vector<int>&vec){
        if(root==NULL){
           return ;
        }
        
        if(root->left!=NULL){
            solve(root->left, vec);
        }
        if(root->right!=NULL){
            solve(root->right, vec);
        }
        vec.push_back(root->val);

        return ;
    }
   vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;

        solve(root, ans);
        return ans;
    }
};