
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
            dummy->next=new ListNode(sum);
            dummy=dummy->next;
            temp=temp->next;
            if(temp->next==nullptr){break;}
        }
        return node->next;
    }
};

