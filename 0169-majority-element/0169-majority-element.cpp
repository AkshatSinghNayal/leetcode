class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp; 
        priority_queue<pair<int,int>>pq;
        for(auto& it : nums ){
            mp[it]++; 
        }

        for(auto& [ele,freq] : mp ){
            pq.push({freq,ele}); 
        }
        return (!pq.empty()) ? pq.top().second : -1; 
    
    }
};