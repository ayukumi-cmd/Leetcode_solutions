
class Solution {
public:
bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* p, TreeNode* q) {
        if (p==NULL && q==NULL) {
            return true;
        } else if (p==NULL || q==NULL) {
            return false;
        }
        
        if (p->val != q->val) {
            return false;
        }
        
        return helper(p->left,q->right) && helper(p->right, q->left); 
    }
};