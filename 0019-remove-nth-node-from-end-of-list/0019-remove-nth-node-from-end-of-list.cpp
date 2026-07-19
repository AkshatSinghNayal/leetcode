class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};