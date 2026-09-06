class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int,int> mp ; 
        mp[0]=1;
        int count = 0;
        long long sum= 0; 

        for(auto& it : nums ){
            sum+=it;
            int needed = sum-k;
            if(mp.count(needed)){
                count+=mp[needed]; 
            }
            mp[sum]++; 
            
        }
        return count;
    }
};