class Solution {
public:

    class comp{
        public:
        bool operator()(const pair<int,int>& a , const pair<int,int>& b ){
            return a.first > b.first;
        }
    }; 

    bool isNStraightHand(vector<int>& hand, int gsize) {
        int n = hand.size(); 
        unordered_map<int,int> mp ;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq; 
        if( n%gsize != 0 ) return false;
        for(auto& it : hand ){
            mp[it]++; 
        }

        for(auto& it : mp ){
            pq.push({it.first , it.second}); 
        }
        

        while(!pq.empty()){
            int temp = gsize;
            int last = INT_MAX; 
            mp.clear();
            while(temp-- ){
                auto [ ele , freq ]=  pq.top(); pq.pop(); 
                if( last != INT_MAX and last != ele-1 ) return false;
                last = ele; freq-=1;
                if( freq ){
                    mp[ele] = freq;
                }
            }
            for(auto& it  : mp ){
                pq.push({it.first , it.second }); 
            }
        }
        return true;
    }
};