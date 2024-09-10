class Solution {
public:

    bool subPath(ListNode* head,ListNode* curr,TreeNode* root) {
        if(curr == NULL){return 1;}
        if(root == NULL){return 0;}
        
        if(curr->val == root->val){
            curr = curr->next;
        }
        else if(head->val == root->val){
            head = head->next;
        }
        else{
            curr = head;
        } 

        return subPath(head,curr,root->left) || subPath(head,curr,root->right);
    }

    bool isSubPath(ListNode* head,TreeNode* root) {
        return subPath(head,head,root);
    }
};