class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Empty list case
        if (head == nullptr) {
            return nullptr;
        }
        
        // Single node case
        if (head->next == nullptr) {
            // For LeetCode, we might not need to manually delete
            // delete head; // Commented out as it might cause issues
            return nullptr;
        }

        // Find the middle node using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        // When fast reaches the end, slow will be just before the middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Delete the middle node (no explicit memory deallocation for LeetCode)
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        // delete toDelete; // Commented out as it might cause issues on LeetCode
        
        return head;
    }
};