
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int  prev = INT_MAX;  
        ListNode* dummy = new ListNode(-1); 
        ListNode* tempo = dummy ; 
        ListNode* temp = head; 
        while(temp){
            
            if( prev != temp->val ){
                prev = temp->val; 
                cout<< prev << " " ; 
                tempo->next = temp; 
                tempo = tempo->next;
            }
            temp = temp->next; 
            
        }
        if( tempo and  prev == tempo->val ) tempo->next = nullptr ;
        return dummy->next; 
    }
};