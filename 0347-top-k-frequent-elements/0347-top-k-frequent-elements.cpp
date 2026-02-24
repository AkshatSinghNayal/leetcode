class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // int n = nums.size() ; if(n==  1 ) return {nums[0]} ; 
        priority_queue< pair<int,int> , vector<pair<int,int>> , less<pair<int,int>>> pq; 
        unordered_map<int,int> mp ; 
        for( auto& it : nums ){
            mp[it]++; 
        }

        for(auto& it : mp ){
            pq.push({ it.second , it.first }); 
        }

        
        int count = 1 ; 
        vector<int> ans; 
        while(!pq.empty() and count <=k  ){
            auto [ freq , ele ] = pq.top() ; pq.pop() ;
            ans.push_back(ele); 
            count++; 
        }
        return ans  ; 
    }
};