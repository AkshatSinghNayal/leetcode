class Solution {
public:
    int dp[5001][2][2]; 

    int solve( vector<int>& prices , int i , int buy , int cooldown ){
        //base 
        if( i >= prices.size() ) return 0;

        if( dp[i][buy][cooldown] != -1 ) return dp[i][buy][cooldown]; 

        int maxi = INT_MIN; 

        if( buy ){
            int bought= INT_MIN ; 
            int notBought = solve(prices , i+1 , true , false ); 
            if(!cooldown)  bought = -prices[i]+solve(prices , i+1 , false , false ); 
            

            maxi = max({bought , notBought , maxi}); 
        }
        else{
            int sold = prices[i]+solve(prices , i+1 , true , true ); 
            int notSold = solve( prices , i+1 , false , false); 
            maxi  = max({maxi, sold , notSold}); 
        }

        return dp[i][buy][cooldown] = maxi ;

    }

    int maxProfit(vector<int>& prices) {
        memset(dp , -1, sizeof(dp)); 
        return solve( prices , 0 , true , false ); 
    }
};