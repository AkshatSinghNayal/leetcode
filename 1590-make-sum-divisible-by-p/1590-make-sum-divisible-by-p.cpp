class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = accumulate(nums.begin() , nums.end() , 0LL); 
        unordered_map<int,int>mp;
        mp[0] =-1;
        long long prefix= 0 ; 
        int target = total%p;
        if(target % p == 0  ) return 0;
        int n = nums.size();
        int maxi = n;

        for(int i = 0 ;i<n; i++ ){
            prefix= (prefix+nums[i])%p; 
            int complement = ( (prefix - target)%p + p )%p;
            if( mp.count(complement)){
                maxi = min( maxi, i-mp[complement]);
            }
            mp[prefix] = i; 
        }
        cout<<maxi;
        return maxi == n ? -1 : maxi ; 
    }
};