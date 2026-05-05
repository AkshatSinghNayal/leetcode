class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or k == 0 or !head->next) return head; 
        int count = 0;
        ListNode* temp = head; 
        ListNode* dummy= head;
        ListNode* take = head;  
        while(temp){
            count++; 
            if(!temp->next) dummy = temp; 
            temp = temp->next;
        }
        k = k%count; 
        if(k==0) return head;
        int reach = count -k ; 
        temp = head; 
        while(reach-- and temp ){
            if(reach == 0  ){
                take = temp->next;
                temp->next = nullptr;
                break;
            }
            temp = temp->next;
        }
        dummy->next = head; 
        head=take;
        return head;
        
    }
};