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
    int getDecimalValue(ListNode* head) {
        ListNode* curr=head; 

        vector<int>ans; 
        while(curr!=NULL){
            ans.push_back(curr->val);
            curr=curr->next;
        }

        reverse(ans.begin(), ans.end()); 
        int num=0;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]==0){continue;}
           num+=(pow(2,i)*ans[i]);
        }


        return num;
    }
};