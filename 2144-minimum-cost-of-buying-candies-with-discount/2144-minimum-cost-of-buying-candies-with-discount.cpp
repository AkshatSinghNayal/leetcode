class Solution {
public:
    int minimumCost(vector<int>& cost) {
        priority_queue<int>pq(cost.begin(),cost.end()); 
        int count =0; 
        int total =0 ;
        while(!pq.empty()){
            if(count == 2 ){
                count = 0; 
                pq.pop();
                continue;
            }
            count++;
            total+=pq.top(); pq.pop();
        }
        return total;
    }
};