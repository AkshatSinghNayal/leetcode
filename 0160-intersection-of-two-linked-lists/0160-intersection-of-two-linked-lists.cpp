/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int lengthFind(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        int len1 = lengthFind(headA);
        int len2 = lengthFind(headB);
       
        int totalLen = abs(len1-len2);
         while (totalLen > 0) {
            if (len1 > len2) headA = headA->next;
            else headB = headB->next;
            totalLen--;
        }

        while( headA ){
            if( headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};