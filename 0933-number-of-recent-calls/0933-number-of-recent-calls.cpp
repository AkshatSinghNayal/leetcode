class RecentCounter {
public:

    class comp{
        public:
        bool operator()(const int& a , const int&b ){
            return a > b; 
        }
    }; 

    priority_queue<int,vector<int>,comp>pq;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        if(pq.empty()){
            pq.push(t); 
            return 1; 
        }
        else{
            while(!pq.empty() and pq.top() < (t-3000) ){
                pq.pop();
            }
            pq.push(t);
        }
        return pq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
