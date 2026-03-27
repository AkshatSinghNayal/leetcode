class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>,less<int>>pq;
        for(auto& it : stones) pq.push(it); 
        
        while(pq.size()>1 ){
            
            int top = pq.top(); 
            pq.pop(); 
            int secondTop = pq.top();
            pq.pop(); 

            if( top == secondTop ){
                continue;
            }
            else{
                pq.push( top - secondTop );
            }
            
        }
    
        return (!pq.empty()) ? pq.top() : 0 ; 
    }
};