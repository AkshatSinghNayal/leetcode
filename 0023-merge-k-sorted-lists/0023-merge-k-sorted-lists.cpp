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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< pair< int , ListNode* > , vector< pair < int , ListNode* >> , greater< pair<int, ListNode*>> > pq ; 

        for(int i = 0; i < lists.size(); i++) {
    if(lists[i]) pq.push({lists[i]->val, lists[i]}); // take care of the empty or the null list here ->>>> forgot one time next time b careful ; 
}


        ListNode* dummy = new ListNode ( -1 ) ; 
        ListNode* temp =dummy ; 
        while( !pq.empty()){
            ListNode* node = pq.top().second ; 
            pq.pop(); 
            temp->next = node ; 
            temp = temp->next ; 
            if( node->next ){
                pq.push({node->next->val , node->next}); 
            } 
        }
        return dummy->next; 
    }
};