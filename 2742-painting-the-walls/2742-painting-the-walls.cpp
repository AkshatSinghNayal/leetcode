class Solution {
public:
    int dp[501][501]; 

    int solve(vector<int>& cost, vector<int>& time , int n , int i  ){
        //base
        if( n <= 0  ) return 0 ;
        if( i >= cost.size() and n!= 0 ) return INT_MAX;  

        if( dp[i][n]!= -1 ) return dp[i][n]; 
        
        
        long long paid = 0LL+cost[i]+solve( cost , time , max(0,n-time[i]-1), i+1);
        long long free = solve(cost ,time , n , i+1 ); 
        
        return dp[i][n] = min(paid , free ); 


    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp,-1,sizeof(dp)); 
        int n  = cost.size(); 
        return solve( cost , time , n , 0); 
    }
};