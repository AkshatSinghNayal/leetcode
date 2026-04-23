class Solution {
public:

    int solve(vector<vector<int>>&dp, int i , int amount , vector<int>& nums ){
        //base  

        if( i== 0 ){
            if( amount% nums[i] == 0  ) return 1 ; 
            return 0; 
        }

        if(dp[i][amount] != -1 ) return dp[i][amount]; 
        int take = 0; 
        if( nums[i] <= amount ){
            take = solve(dp , i , amount-nums[i] , nums ); 
        }
        int notTake = solve( dp , i-1 , amount , nums ); 

        return dp[i][amount] = (take+notTake); 
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        vector<vector<int>>dp(n , vector<int>(amount+1 , -1)); 
        return solve( dp , n-1 , amount , coins ); 
    }
};