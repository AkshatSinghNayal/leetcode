class EventManager {
public: 

    class comp{
        public: 
        bool operator()(const pair<int,int>& a , const pair<int,int>& b ){
            if(a.first == b.first ){
                return a.second > b.second ; 
            }
            return a.first < b.first;
        }
    }; 


    unordered_map<int,int>mp; 
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
    EventManager(vector<vector<int>>& events) {
        for(auto& it : events){
            mp[it[0]] = it[1]; 
            pq.push({ it[1], it[0]}); 
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId]=newPriority;
        pq.push({newPriority , eventId}); 
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto [ priorityy , id ] = pq.top(); pq.pop(); 
            if( mp.count(id) and mp[id] == priorityy  ){
                mp.erase(id);
                return id;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */