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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* node=dummy;
        ListNode* temp=head;
       
       
        while(true){
             int sum=0;
            while(temp->next!=nullptr and temp->next->val!=0){
                temp=temp->next;
                sum+=temp->val;
                }
            node->next=new ListNode(sum);
            node=node->next;
            temp=temp->next;
            if(temp->next==nullptr){break;}
        }
        return dummy->next;
    }
};

