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
        if(!node) return nullptr;
        unordered_map<Node*,Node*>mp;
        unordered_set<Node*>st;
        Node* temp = new Node(node->val);
        mp[node]=temp;
        queue<pair<Node*,Node*>>q;

        for(auto& it : node->neighbors) {
            q.push({it,node}); 
        }
        st.insert(node);   
        
        while(!q.empty()){

            int size = q.size(); 

            while(size--){

                auto [ newNode , parent ] = q.front() ; q.pop(); 

                if(!mp.count(newNode)){
                    Node* temp = new Node(newNode->val);
                    mp[newNode]=temp;
                    mp[parent]->neighbors.push_back(temp);
                }
                else{
                    mp[parent]->neighbors.push_back(mp[newNode]);
                }

                if(st.count(newNode)) continue;
                st.insert(newNode); 
                for(auto& it : newNode->neighbors){
                    q.push({ it , newNode});
                }

            }

        }


        // // if(node)cout<<node->val;    
        // for(auto& it : node->neighbors) {
        //     if(it){
        //         cout<<it->val<<" ";
        //     }
        // }

        return temp;
    }
};