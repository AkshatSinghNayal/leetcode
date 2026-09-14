/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if( node ==  NULL ) return nullptr; 
        unordered_map<Node* , Node*>mp; 
        queue<Node*>q; 
        q.push(node);
        Node* head =  new Node(node->val); 
        mp[node] = head; 

        while(!q.empty()){

            auto temp  = q.front(); q.pop(); 

            int val = temp->val; 
            auto vec =  temp->neighbors; 


            for(auto& it : vec){
                if( mp.find(it) == mp.end()){
                    Node* ok = new Node(it->val); 
                    mp[temp]->neighbors.push_back(ok);
                    mp[it] = ok;
                    q.push(it); 
                }
                else{
                    mp[temp]->neighbors.push_back(mp[it]); 
                }
            }



        }
        return mp[node]; 

    }
};