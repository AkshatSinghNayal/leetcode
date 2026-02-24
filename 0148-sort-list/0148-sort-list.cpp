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

    ListNode* merging( ListNode*& left , ListNode*& right ){
        ListNode* temp =  new ListNode(-1);
        ListNode* dummy = temp ; 
        while( left and right ){
            if( left->val < right->val ){
                dummy->next = left; 
                left = left->next;
            }
            else{
                dummy->next = right; 
                right = right->next;
            }
            dummy = dummy->next;

        }

        if(left){
            dummy->next = left ; 
        }

        if(right){
            dummy->next = right ; 
        }

        return temp->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head or !head->next ) return head; 
        ListNode* slow = head , *fast =head->next; 

        while( fast and fast->next){
            slow = slow->next; 
            fast=fast->next->next; 
        }

        ListNode* start = head ;
        fast = slow->next ;                                                           
        slow->next = nullptr ; 

        auto left = sortList(start); 
        auto right = sortList(fast); 

        return merging( left , right ); 

    }
};