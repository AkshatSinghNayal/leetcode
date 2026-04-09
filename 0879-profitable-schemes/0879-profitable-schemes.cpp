class Solution {
public:
    const int MOD = 1e9+7;

    int solve(vector<vector<vector<int>>>&dp , int i , int n, int minProfit, vector<int>& group, vector<int>& profit ){
        // base
        minProfit = max(0 , minProfit );
        if( i< 0 ){
            return (minProfit == 0 ) ? 1 : 0 ; 
        }

        if( dp[i][n][minProfit] != -1 ) return dp[i][n][minProfit]; 

        long long take = 0; 
        if( n-group[i]>=0 ){
            take = solve( dp , i-1 , n-group[i], minProfit- profit[i] , group , profit );
        }
        long long notTake = solve( dp , i-1 , n , minProfit , group , profit );

        return dp[i][n][minProfit] = (take+notTake)%MOD;
        
    }            

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size(); 
        vector<vector<vector<int>>>dp( m , vector<vector<int>>( n+1 , vector<int>(minProfit+1 , -1))); 
        return solve( dp, m-1 , n , minProfit , group , profit  ); 
    
    }
};