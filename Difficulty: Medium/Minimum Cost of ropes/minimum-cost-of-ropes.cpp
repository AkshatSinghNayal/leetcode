class Solution {
  public:
    
    class comp{
        public: 
        bool operator()(const int a , const int b ){
            return a>b ; 
        }
    };
  
    int minCost(vector<int>& arr) {
       int global = 0;  
       priority_queue<int ,vector<int> , comp>pq(arr.begin() , arr.end()); 
       if(arr.size() ==  1 ) return 0; 
       while(!pq.empty()){
           int mini = 0; 
           mini+=pq.top(); pq.pop(); 
           if(!pq.empty()){
               mini+=pq.top(); 
               pq.pop(); 
           }
           global += mini;
           if(pq.empty()) break;
           pq.push(mini); 
       }
       return global; 
       
    }
};