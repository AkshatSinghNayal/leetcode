class Solution {
public:

    class comp{
        public : 
        bool operator()( pair<int,int>&a , pair<int,int>& b ){
            auto [ freq1 , a1 ] = a;
            auto [freq2 , b1 ] = b; 
            return freq1<freq2;
        }
    };

    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp; 
        priority_queue<pair<int,int>,vector<pair<int,int>>, comp>pq;
        for(auto& it : nums ){
            mp[it]++; 
        }

        for(auto& [ele,freq] : mp ){
            pq.push({freq,ele}); 
        }
        return (!pq.empty()) ? pq.top().second : -1; 
    
    }
};