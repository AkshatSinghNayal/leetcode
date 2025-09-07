class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (l1 || l2 || carry) {
            int digit1 = (l1 ? l1->val : 0);
            int digit2 = (l2 ? l2->val : 0);

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
