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
    ListNode* deleteMiddle(ListNode* head) {
        // Empty list
        if (head == nullptr) {
            return nullptr;
        }
        
        // Single node case - this is the middle, so delete it
        if (head->next == nullptr) {
            // On LeetCode, we may not need to manually delete nodes
            // delete head; // Removing explicit delete
            return nullptr;
        }
        
        // Special case - for two nodes, the second one is the middle
        if (head->next->next == nullptr) {
            head->next = nullptr;
            // delete middle; // Removing explicit delete
            return head;
        }
        
        // For lists with 3 or more nodes
        ListNode* slow = head;
        ListNode* fast = head->next->next; // Start fast two steps ahead
        
        // When fast reaches the end, slow will be just before middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next) fast = fast->next; // Move fast two steps
        }
        
        // Skip the middle node
        slow->next = slow->next->next;
        // No explicit delete for LeetCode
        
        return head;
    }
};