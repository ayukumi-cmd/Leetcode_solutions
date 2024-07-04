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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode* node = head;
        int count = 0;
        bool inComponent = false;

        while (node != nullptr) {
            if (numSet.find(node->val) != numSet.end()) {
                if (!inComponent) {
                    inComponent = true;
                    count++;
                }
            } else {
                inComponent = false;
            }
            node = node->next;
        }

        return count;
    }
};
