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
        int len = 0 ;
        if( head == nullptr || head->next == nullptr || k==0) return head ; 
        ListNode* temp = head ; 
        while(temp){
            len++; 
            temp = temp->next ;
        }
        k =k%len ;
        if( k == 0 ) return head ; 
        int digitsToShift = len - k ;
        temp = head; 
        while(digitsToShift>1){
            temp = temp->next;
            digitsToShift--; 
        }
        ListNode* t1 = temp->next;
        temp->next = nullptr ; 
        ListNode* t2 = t1 ;
        while(t1->next){
            t1 = t1->next;
        }
        t1->next = head ; 
        head = t2 ; 
        return head ; 

    }
};