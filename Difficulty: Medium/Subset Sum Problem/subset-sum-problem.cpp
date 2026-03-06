class Solution {
  public:
    bool isSubsetSum(vector<int>& nums, int sum) {
        // code here
        int n = nums.size() ;
        vector<int>dp( sum+1 , false ); 
        dp[0]  = true; 
        if( nums[0] <= sum ) dp[nums[0]] = true;
        
        for( int i  = 1 ; i< n ; i++ ){
            for( int target= sum ; target >= 0  ; target-- ){
                dp[target] |= ( nums[i] <=target ) ? dp[target - nums[i]] : false; 
                
                if( dp[sum]) return true;
            }
        }
        return false; 
    }
};