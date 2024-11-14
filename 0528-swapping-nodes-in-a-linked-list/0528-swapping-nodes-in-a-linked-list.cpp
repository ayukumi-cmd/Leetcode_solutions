/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* req(ListNode*head, int k){
        ListNode* curr= head; 
        int cnt=0;
        while(curr!=NULL  and cnt!=k){
                curr= curr->next; 
                cnt++;
        }
        return curr;
    }
    ListNode* swapNodes(ListNode* head, int k) {

        int n=0; 
        ListNode* curr=head; 

        while(curr!=NULL){
            n++; curr= curr->next;
        }


        ListNode* res1= req(head, k-1);
        ListNode* res2= req(head, n-k);

        int data1= res1->val; 
        int data2= res2->val; 
        res1->val=data2; 
        res2->val=data1;
        return head;
    }
};