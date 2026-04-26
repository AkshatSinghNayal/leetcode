class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size() ; 
        if( n<3 ) return-1 ; 
        int mini = INT_MAX ; 
        unordered_map<int,vector<int>>mp; 
        for(int i = 0 ; i< n; i++ ){
            mp[nums[i]].push_back(i); 
        }

        for(auto& it : mp ){
            auto [ele , vec] = it; 
            if(vec.size() <3) continue; 
            int size = vec.size();
            for(int i =0 ; i<size ; i++ ){
                int j = (i+1)%size; 
                int k = (i+2)%size; 
                mini = min({ mini , abs( abs(vec[i]-vec[j])+abs(vec[j]-vec[k]) +  abs(vec[k]-vec[i]) )}); 
            } 

        }
        
        return (mini== INT_MAX) ? -1 : mini;
    }
};