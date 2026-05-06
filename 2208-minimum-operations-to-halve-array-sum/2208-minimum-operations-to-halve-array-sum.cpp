class Solution {
public:
    int halveArray(vector<int>& nums) {
        double total = accumulate(nums.begin() , nums.end(),0LL);
        double temp=total/2;  
        priority_queue<double>pq(nums.begin(), nums.end());
        int count = 0; 
        while(!pq.empty()){
            if(!pq.empty() and total>temp){
                count++;
                auto top = pq.top(); pq.pop();
                total-=top;
                total+=top/2;
                pq.push(top/2);  
            }
            else{
                break; 
            }
        }
        return count;
    }
};