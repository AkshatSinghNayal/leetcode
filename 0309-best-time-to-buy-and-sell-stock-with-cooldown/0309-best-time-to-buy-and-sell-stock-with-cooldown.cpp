class Solution {
public:
    int dp[5001][2]; 

    int solve( vector<int>& prices , int i , int buy){
        //base 
        if( i >= prices.size() ) return 0;

        if( dp[i][buy] != -1 ) return dp[i][buy]; 

        int maxi = INT_MIN; 

        if( buy ){
            int notBought = solve(prices , i+1 , true ); 
            int bought = -prices[i]+solve(prices , i+1 , false); 
            

            maxi = max({bought , notBought , maxi}); 
        }
        else{
            int sold = prices[i]+solve(prices , i+2 , true ); 
            int notSold = solve( prices , i+1 , false ); 
            maxi  = max({maxi, sold , notSold}); 
        }

        return dp[i][buy]= maxi ;

    }

    int maxProfit(vector<int>& prices) {
        memset(dp , -1, sizeof(dp)); 
        return solve( prices , 0 , true ); 
    }
};