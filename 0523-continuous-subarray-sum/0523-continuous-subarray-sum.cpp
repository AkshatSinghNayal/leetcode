class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp ;
        mp[0]= -1  ; 
        long long sum =  0 ;
        for( int i = 0  ; i<nums.size() ; i++){
            sum = (sum+nums[i])%k ; 
            if( mp.count(sum)){
                if(i - mp[sum]>=2){
                    return true; 
                }
            }
            else{
                mp[sum] =  i ; 
            }
        }
        return false;
    }
};