class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0; 
        unordered_map<int,int>freq; 
        freq[0] =1 ; 
        long long sum = 0; 
        for(auto& it  : nums ){
            sum=((sum+it)%k +k)%k; 
            if(freq.count(sum)){
                ans+=freq[sum]; 
            }
            freq[sum]++; 
        }
        return ans; 
    }
};