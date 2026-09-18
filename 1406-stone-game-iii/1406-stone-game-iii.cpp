class Solution {
public:

    int solve(vector<int>&stone , vector<vector<int>>&dp , int i , int n , int player ){
        //base
        if(i>=n) return 0;

        if(dp[i][player] != INT_MIN ) return dp[i][player]; 

        int maxi = INT_MIN;
        if(player){
            int total = 0; 
            for(int idx = 0 ; idx<3 and idx+i < n ; idx++ ){
                int index = idx+i;
                total+=stone[index]; 

                int cost = total+solve(stone , dp , index+1 , n , 1-player);
                maxi = max(maxi , cost);
            }
            return dp[i][player] = maxi;
        }
        else{
            int mini = INT_MAX; 
            for(int idx = 0; idx<3 and idx+i < n ; idx++ ){
                int cost = solve(stone,dp,idx+i+1,n,1-player);
                mini = min(mini,cost);
            }
            return dp[i][player] = mini;
        }
        return -1;
    }

    string stoneGameIII(vector<int>& stone) {
        int n  = stone.size();
        vector<vector<int>>dp(n,vector<int>(2,INT_MIN)); 
        double total = accumulate(stone.begin() , stone.end() , 0LL );
        int ans = solve(stone,dp ,0,n,1); 
        return ( total - ans < ans )  ? "Alice" : ( total - ans == ans ) ? "Tie" : "Bob";
    }
};