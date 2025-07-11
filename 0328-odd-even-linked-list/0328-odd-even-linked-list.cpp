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
    ListNode* oddEvenList(ListNode* head) {
        if(head ==nullptr || head->next ==nullptr) return head;
        ListNode* fast = head; 
        ListNode* slow = head->next;
        ListNode* temp = head->next;
        while(fast && fast->next && fast->next->next){
            fast->next=slow->next ;
            fast = slow->next;
            slow->next = fast->next;
            slow=fast->next;
        }
        fast->next=temp;
        return head;
    }
};