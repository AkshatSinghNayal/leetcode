class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0; 
        unordered_map<int,int>freq; 
        freq[0] =1 ; 
        long long sum = 0; 
        for(auto& it  : nums ){
            sum=(sum+it)%k;
            int target = ( sum + k )%k;
            if(freq.count(target)){
                ans+=freq[target]; 
            }
            freq[target]++; 
        }
        return ans; 
    }
};