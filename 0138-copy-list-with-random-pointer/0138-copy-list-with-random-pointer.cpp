/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head; 
        unordered_map<Node*,Node*>mp;  
        Node*temp = head; 
        while(temp){
            mp[temp] = new Node(temp->val); 
            temp = temp->next;
        }
        Node* fa = mp[head]; Node* final = fa; 
        temp = head;
        
        while(temp){
            if(temp->next) final->next = mp[temp->next]; 
            if(temp->random) final->random = mp[temp->random]; 
            temp=temp->next;
            final = final->next;
            
        }

        return fa;

    }
};