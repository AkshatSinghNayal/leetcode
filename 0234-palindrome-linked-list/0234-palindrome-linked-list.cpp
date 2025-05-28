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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        // 1. Count the number of nodes
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        
        // 2. Move to the middle
        int mid = count/2;
        ListNode* firstHalf = head;
        ListNode* secondHalf = head;
        for (int i = 0; i < mid; ++i) {
            secondHalf = secondHalf->next;
        }
        // If odd, skip the middle node
        if (count % 2 != 0) {
            secondHalf = secondHalf->next;
        }
        
        // 3. Reverse the second half
        ListNode* prev = nullptr;
        while (secondHalf) {
            ListNode* nextTemp = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = nextTemp;
        }
        
        // 4. Compare values in both halves
        ListNode* p1 = head;
        ListNode* p2 = prev;
        for (int i = 0; i < mid; ++i) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};