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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if( !head || !head->next || k==0) return head ;  
        int count =0 ; 
        while( temp ) {
            count++ ; 
            temp = temp->next ; 
        }
        k = k%count ; 
        if( k == 0 ) return head ; 
        int index = count - k - 1; 
        temp = head ; 
        for( int i = 0 ; i<index ; i++) temp = temp->next; 
        ListNode* tail = temp->next ; 
        ListNode* newHead = tail ;
        temp->next = nullptr ; 
        while(tail->next!=nullptr){
            tail = tail->next ;
        }
        tail->next = head ; 
        return newHead;
    }
};