class Solution {
public:

    int dp[101][101][101];
    const int MOD = 1e9+7; 


    int solve(int i , int minProfit,vector<int>& group, vector<int>& profit ,int n ){
        //base 

        if( i < 0 ){
            return minProfit == 0 ? 1 : 0 ; 
        }
        
        if(dp[i][minProfit][n] != -1 ) return dp[i][minProfit][n] ; 

        long long  take = (n>= group[i] and minProfit >=0 ) ? solve(i-1, max(0,minProfit-profit[i]), group, profit ,  n-group[i]) : 0 ; 
        long long  notTake = solve(i-1,minProfit , group , profit , n ); 

        return dp[i][minProfit][n] = ( 0LL+take + notTake )%MOD;  

    }


    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp)); 
        return solve(group.size() -1 ,minProfit,group,profit, n ); 
    }
};