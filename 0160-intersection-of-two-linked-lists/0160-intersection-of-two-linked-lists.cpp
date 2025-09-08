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
        ListNode* finalPtr;

        int totalLen = (max(len1, len2) - min(len1, len2));
        if (len1 > len2) {
            finalPtr = headA;
            
        } else {
            finalPtr = headB;
            
        }
        while (totalLen > 0) {
                finalPtr = finalPtr->next;
                totalLen--;
            }
            
        ListNode* smaller;
        if (len1 <= len2) {
            smaller = headA;

        } else {
            smaller = headB;
        }

        while (finalPtr) {
            if (finalPtr == smaller) {
                return finalPtr;
            }
            finalPtr = finalPtr->next;
            smaller = smaller->next;
        }

        return nullptr;
    }
};