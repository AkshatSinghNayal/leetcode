class Solution {
public: 

    int solve( vector<int>& nums , vector<int>& dp , int n ) {

        if( n < 0 ){
            return 0; 
        }
        if( dp[n] != -1 ) return dp[n]; 

        int take= nums[n] + solve ( nums , dp , n-2); 
        int notTake =  solve( nums , dp , n-1 ) ; 

        return dp[n] = max( take , notTake )  ;
        
    }

    int rob(vector<int>& nums) {
       int n =  nums.size() ;
       if( n ==1 ) return nums[0]; 
       vector<int> dp(n,-1) ;
       dp[0]; 


    return solve( nums , dp , n-1);

       
    }
};