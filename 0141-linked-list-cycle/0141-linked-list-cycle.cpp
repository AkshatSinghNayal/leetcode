class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        while (head != nullptr) {
            if (visited.find(head) != visited.end()) {
                return true; // cycle detected
            }
            visited.insert(head);
            head = head->next;
        }

        return false; // no cycle
    }
};
