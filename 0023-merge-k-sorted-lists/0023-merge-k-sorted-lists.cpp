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

    void mergeAns ( vector<ListNode*> & ans  , ListNode*& temp ){
        
        for( int i = 0 ; i<ans.size() ; i++){
            temp->next = ans[i]; 
            temp= temp->next ; 
        }
        temp->next = nullptr ; 
        
    }

    ListNode* mergeKLists(vector<ListNode*>& list) {
        vector<ListNode*> ans ; 
        for( int i =  0 ; i<list.size() ; i++){
            // if( !list[i] ) continue; 
            ListNode * temp = list[i] ;
            while( temp) {
                ans.push_back(temp); 
                temp  = temp->next ; 
            }
        }
        sort(ans.begin(), ans.end(), [](ListNode* a, ListNode* b) {
            return a->val < b->val;
        });
        ListNode* head = new ListNode (-1); 
        ListNode * temp = head ; 
        mergeAns( ans , temp  ); 
        return head->next ; 
    }
};