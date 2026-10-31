class MyCalendarTwo {
public:
    vector<pair<int,int>>b,s;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
            for(auto&[start , end] : s ){
                if( max(start , startTime) < min(endTime , end) ) return false;
            }
            
            for(auto& [ start , end ] : b ){
                if( max( start , startTime) < min( end , endTime ) ){
                    s.push_back({  max( start , startTime) ,min( end , endTime )  }); 
                }
            }
            b.push_back({startTime , endTime }); 
            return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */