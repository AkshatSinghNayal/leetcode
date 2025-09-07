class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
         int digit1 ; 
         int digit2;
        while (l1 || l2 || carry) {
            if(l1 != nullptr){
                digit1 = l1->val;
            }
            else{
                digit1 = 0 ; 
            }
            if( l2 != nullptr){
                digit2 = l2->val ;
            }
            else{
                digit2 = 0;
            }

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;

            temp->next = new ListNode(sum % 10);
            temp = temp->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next;
    }
};
