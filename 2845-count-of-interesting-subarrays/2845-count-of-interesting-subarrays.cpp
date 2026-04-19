class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int MOD, int k) {
        int n = nums.size(); 
        unordered_map<int,int>freq; 
        freq[0] =1 ; 
        
        long long currentMOD = 0 , ans = 0; 
        for(auto& temp : nums ){
            int it = ( temp%MOD == k ) ? 1 : 0 ; 
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

// if nums[i]%MOD == k then count++ in arr = nums[i ........ n-1 ]
// we can take nums[i] in terms of 0 and 1 
// and while traversing we get the countSum 

// here we have to find the sum of count such that its mod == k

// so for that we have taken (curr - prev)%mod  = k 
// so curr%mod - k = prev%mod

// if .............currMOD%MOD - k = prev
// nd ......prev..................... we remove prev to get currMOD%MOD == k