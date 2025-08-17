class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited; // track visited nodes
        ListNode* temp = head;
        
        while(temp){
            if(visited.find(temp) != visited.end()){
                return temp;
            }
            visited.insert(temp);
            temp = temp->next;
        }
        
        return nullptr; // no cycle
    }
};
