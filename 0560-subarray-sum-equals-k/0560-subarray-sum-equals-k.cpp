class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp; 
        mp[0] = 1; int ans =0 ; 
        long long sum = 0; 
        for(auto& it : nums){
            sum+=it;
            int compliment = ( sum- k );
            if(mp.count(compliment)) {
                ans+=mp[compliment]; 
            }
            mp[sum]++; 
        }
        return ans; 
    }
};