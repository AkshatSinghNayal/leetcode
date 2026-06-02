class Solution {
public:

    class comp{
        public: 
        bool operator()(int a , int b ){
            return a> b ; 
        }
    }; 

    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , comp>pq ; 
        
        for(auto& it : nums ){
            pq.push(it); 
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top(); 
    }
};