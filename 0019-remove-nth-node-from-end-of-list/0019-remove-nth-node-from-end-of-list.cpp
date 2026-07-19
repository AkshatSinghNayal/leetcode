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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0; 
        ListNode* dummy = new ListNode (-1 ,head); 
        ListNode* temp = dummy; 
        while(temp){
            len++; 
            temp = temp->next; 
        }

        temp = dummy; 
        len-=n;

        while(len>1){
            temp=temp->next;
            len--;
        }

        ListNode* ok = temp->next;        
        temp->next = ok->next;
        delete(ok); 


        return dummy->next;


    }
};