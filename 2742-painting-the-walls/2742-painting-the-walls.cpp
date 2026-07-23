class Solution {
public:
    int dp[501][501];

    int solve(vector<int>& cost, vector<int>& time, int i, int walls) {
        // Base case: All walls are painted
        if (walls <= 0) return 0;
        if(i>=cost.size() ) return 1e9; 

        if(dp[i][walls] != -1 ) return dp[i][walls]; 

        int take = solve(cost,time,i+1 , walls-1-time[i]);
        if(take != 1e9 ) take+=cost[i] ;

        int notTake = solve(cost,time,i+1 , walls ); 

        return dp[i][walls] = min(take, notTake);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof(dp)); 
        int n = cost.size();
        return solve(cost, time, 0, n); 
    }
};