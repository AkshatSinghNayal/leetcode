class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = accumulate(nums.begin() , nums.end(),0LL); 
        if( total % p ==0) return 0;
        unordered_map<int,int>mp; 
        mp[0] = -1;
        long long target = total%p; 
        long long sum =0; 
        int i = 0 , n = nums.size();
        int mini = n; 
        while( i < n ){
            sum = (sum+nums[i])%p;
            int comp = ( (sum - target)+p )%p;
            if(mp.count(comp)){
                mini = min(mini , i-mp[comp]); 
            }
            mp[sum] =i; 
            i++; 
        }
        return mini == n ? -1 : mini; 
    }
};

// 3 4 
// target = 4

// current - something = target
// current-target = something ?
