class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin() , stones.end()); 
        if(pq.size() ==1 ) return pq.top(); 
        while(!pq.empty()){
            int first = pq.top(); pq.pop(); 
            int second = INT_MIN;
            if( !pq.empty()){
                second = pq.top(); pq.pop(); 
            }
            if( second == INT_MIN ) return first; 
            else if( first > second ) pq.push( first-second);  

        }
        return 0; 
    }
};