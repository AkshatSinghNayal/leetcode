class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int> mp;
        mp[0] = -1 ;
        long long target  = 0; 
        int n = nums.size();
        for(auto& it : nums ){
            target =(target+ it)%p;
        }
        if( target == 0 ) return 0 ;

        int prefix =0 , mini =INT_MAX; 

        for(int i = 0 ;i< n ;i++ ){
            prefix = (prefix+nums[i])%p;
            const int MOD = (prefix - target + p )%p;
            if(mp.count(MOD)){
                mini = min(mini , i-mp[MOD]);
            }
            mp[prefix]=i; 

        }

        return (mini == INT_MAX or mini ==  n ) ? -1 : mini ; 
    }
};


