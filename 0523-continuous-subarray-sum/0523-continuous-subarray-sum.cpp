class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp ; 
        mp[0] = -1 ; 
        int n = nums.size() ; 
        
        int pre = 0 ; 
        for( int i  = 0 ; i<n ; i++){
            pre = (pre+nums[i])%k; 
            if( mp.count(pre)){
                if( i -mp[pre] >= 2 ){
                    return true; 
                }
            }
            else{
                mp[pre] = i ;
            }
        }
        return false;
    }
};