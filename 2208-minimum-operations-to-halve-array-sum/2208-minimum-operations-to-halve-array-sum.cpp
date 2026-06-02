class Solution {
public:
    int halveArray(vector<int>& nums) {
        int count = 0; 
        priority_queue<double>pq(nums.begin() , nums.end()); 
        double total = accumulate(nums.begin() , nums.end() , 0.0 ); 
        double half = (double)total/2.0; 

        while(!pq.empty() and total> half){
            count++;
            double temp = pq.top()/2.0; pq.pop(); 
            cout<<temp << " " ; 
            pq.push(temp); 
            total-=temp;
        }
        cout<<"total->" << total ;
        return count;
    }
};