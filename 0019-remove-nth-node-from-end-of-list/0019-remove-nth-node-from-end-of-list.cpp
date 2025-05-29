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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head ; 
       
        int count= 0 ; 
        while(temp){
            temp=temp->next; 
            count++;
        }  
        count = count-n;
        if( count == 0) {
            ListNode* old = head ; 
            head = head->next ; 
            delete old;
           
        }
        ListNode* tempItr = head; 
        int it = 0 ; 
        while(tempItr){
            if(it == (count-1) && tempItr){
                ListNode* del = tempItr->next;
                tempItr->next= tempItr->next->next;
                delete del ;
                break ;
               

            }
            tempItr=tempItr->next;
            it++;
        }

        
        return head ; 
        }
    
};