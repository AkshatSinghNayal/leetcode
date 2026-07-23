class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1 , 1e9)); 

        for( int i  = 0  ;i<= n ; i++ ){
            dp[i][0] = 0 ;
        }

        for(int i  =n-1 ;i>=0 ;i-- ){
            for(int walls = 1 ; walls<= n; walls++ ){
                
                int take =(walls-1-time[i] <0) ? 0 : dp[i+1][walls-1-time[i]];
                if(take != 1e9 ) take+=cost[i] ;

                int notTake = dp[i+1][walls];

                dp[i][walls] = min(take, notTake);

            }
        }

        return dp[0][n]; 
    }
};