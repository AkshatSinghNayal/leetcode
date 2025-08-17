class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;

        ListNode *slow = head, *fast = head;

        // Step 1: Detect cycle
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break; // cycle detected
        }

        if(!fast || !fast->next) return nullptr; // no cycle

        // Step 2: Find start of cycle
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // start of cycle
    }
};
