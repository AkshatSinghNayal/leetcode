class Solution {
public:
    
    int solve( vector<int>& prices , vector<vector<int>>& dp , int index , int buy , int& n ){

        if( index >= n ) return 0 ; 

        if( dp[index][buy] != -1) return dp[index][buy]; 
        int profit = 0 ; 

        // not buyed anything we have two choices buy or don't buy
        if( buy == 0 ){
            profit = max( -prices[index]+solve( prices , dp , index+1 , 1 ,n) , solve(prices,dp,index+1,0,n)); 
        } 
        else{
            profit = max( prices[index]+solve(prices, dp , index+1 , 0 , n ) , solve(prices ,dp ,index+1 , 1 , n)); 
        }
        return dp[index][buy] = profit ; 
    }

    int maxProfit(vector<int>& prices) {
        int n=  prices.size() ; 
        vector<vector<int>> dp( n , vector<int>(2 ,-1)); 
        return solve( prices , dp , 0 ,0 ,  n); 
    }
};