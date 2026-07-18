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
        ListNode* dummy = new ListNode(-1); 
        ListNode* temp = dummy; 

        ListNode*start = head;
        ListNode* end = head->next;

        while( end ){
            long long sum = 0; 
            if(end->val == 0 ){
                while(start != end ){
                    sum +=start->val;
                    start = start->next;
                }

                temp->next = new ListNode(sum); 
                temp=temp->next;
            }
            end=end->next;

        }
        
        return dummy->next;

    }
};