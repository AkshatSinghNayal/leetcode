class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;

        // Count total nodes
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Go to the middle node
        int mid = count / 2;
        while (mid--) {
            head = head->next;
        }

        return head; // This is the middle node
    }
};
