

class Solution {
public:
    ListNode* head;
    map<pair<TreeNode*, ListNode*>, bool>mp;
    bool solve(TreeNode* root, ListNode* temp) {
        if ( temp == NULL) {
            return true;
        }
        if (root==NULL) {
          return false;
        }
        auto it= make_pair(root, temp);
        if(mp.count(it)){return mp[it]; }
        
        int x= false;
        if(root->val==temp->val){x=x|| solve(root->right, temp->next)||solve(root->left, temp->next);}
         if(head->val ==root->val){
            x=x|| solve(root->right, head->next)||solve(root->left, head->next);
        }
        
             x=x|| solve(root->right, head)||solve(root->left, head);
    

        return mp[it]=x;
    }
    
    bool isSubPath(ListNode* h, TreeNode* root) {
        head = h; 
        mp.clear();
        return solve(root, h)||solve(root->left, h)||solve(root->right, h);
    }
};
