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

    ListNode* rever( ListNode* head ){
        ListNode* prev = nullptr; 
        while(head){
            ListNode* next = head->next; 
            head->next = prev; 
            prev = head; 
            head = next;            
        }
        return prev; 
    }

    int pairSum(ListNode* head) {
        ListNode* dummy = new ListNode(-1); 
        ListNode* temp = head;
        ListNode* ok = dummy;
        while(temp){
            ok->next = new ListNode(temp->val); 
            ok = ok->next;
            temp=temp->next;
        }
        ok = dummy->next;


        temp = rever(head); 
        long long  maxi = 0; 
        while(temp){
             long long sum = temp->val+ok->val; 
             maxi = max(maxi , sum ); 
             temp =temp->next; 
             ok= ok->next; 
        }
        return maxi ; 
    }
};