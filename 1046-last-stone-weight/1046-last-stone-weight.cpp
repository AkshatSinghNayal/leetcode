class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(),stones.end());
        while(!pq.empty()){
            int top = pq.top() ;pq.pop(); 
            int toppy = INT_MAX;
            if(!pq.empty()){
                toppy = pq.top(); pq.pop(); 
            }
            if( toppy == INT_MAX ) return top; 
            if( top>toppy){
                pq.push( top - toppy );
            }
        }
        return 0; 
    }
};