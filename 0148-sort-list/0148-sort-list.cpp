class Solution {
public:
    ListNode* mergeLL(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if (l1 != nullptr) {
            temp->next = l1;
        } else {
            temp->next = l2;
        }
        return dummy->next;
    }

    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* mid = middle(head);

        ListNode* right = mid->next;
        mid->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeLL(left, right);
    }
};