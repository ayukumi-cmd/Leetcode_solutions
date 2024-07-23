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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL){return {};}
        q.push(root);
        vector<vector<int>>ans;

        while(!q.empty()){
            int sz= q.size();
            vector<int>ret;

            for(int i=0; i<sz; i++){
            TreeNode* el=q.front(); q.pop();
            int x= el->val;
             ret.push_back(x);

             if(el->left){q.push(el->left);}
             if(el->right){q.push(el->right);}
            }

           ans.push_back(ret);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
