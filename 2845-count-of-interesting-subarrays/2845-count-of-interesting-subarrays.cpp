class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int MOD, int k) {
        int n = nums.size(); 
        unordered_map<int,int>freq; 
        freq[0] =1 ; 
        for(int i = 0 ;i< n; i++ ){
            nums[i] = ( nums[i]% MOD == k ) ? 1 : 0; 
        }
        long long currentMOD = 0 , ans = 0; 
        for(auto& it : nums ){
            currentMOD = (currentMOD+it)%MOD;
            int target = ( currentMOD -k + MOD)%MOD; 
            if(freq.count(target)){
                ans+=freq[target]; 
            }
            freq[currentMOD]++; 
        }
        return ans; 
    }
};