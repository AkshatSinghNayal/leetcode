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
        if(!head) return head; 
        ListNode*temp = head; 
        int count =0; 
        while(temp){
            count++; 
            temp = temp->next; 
        }
        int rotation = k % count;
        if(rotation ==0 ) return head; 

        temp = head; 
        k = count-rotation; 
        while( temp and --k  ){
            temp = temp->next; 
        }
        ListNode* dummy = new ListNode(); ListNode* tempo = new ListNode(); 
        if(temp->next){
            dummy  = temp->next; 
            tempo = temp->next; 
            temp->next = nullptr ; 
        }

        while(dummy->next) dummy = dummy->next; 
        if(dummy) dummy->next = head; 
        if(tempo) return tempo;
        return head; 

    }
};