class Solution {
public:

    int solve(vector<int>& prices ,vector<vector<int>>&dp, int buy , int day , int n ){
        if( day>=n ) return 0; 

        int profit = 0 ; 
        if( dp[day][buy] != -1 ) return dp[day][buy]; 
        if(buy){
            int bought = solve( prices , dp , false , day+1 , n )- prices[day] ; 
            int notBought = solve( prices ,dp , true , day+1 , n ) ; 

            profit =  max({profit , bought , notBought });
        }
        else{

            int sell =solve(prices , dp ,true , day+1 , n ) + prices[day] ; 
            int notSell = solve( prices , dp , false , day+1 , n ) ; 
            profit = max({profit , sell , notSell}); 
        }
        return dp[day][buy] =  profit; 

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        vector<vector<int>>dp(n,vector<int>(2 , -1)); 

        return solve( prices , dp , true , 0 , n ); 
    }
};