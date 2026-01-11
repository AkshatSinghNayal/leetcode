class Solution {
  public:
    
    int solve(int W, vector<int> &val, vector<int> &wt, vector<vector<int>>& dp , int index   ){
        if(index == 0 ){
            if(wt[0]<= W){
                return val[index];      
            }
            else{
                return 0; 
            }
        }
            
        if( dp[index][W] != -1 ) return dp[index][W]; 
        
        int notTake =  solve( W , val , wt , dp , index - 1 );
        int take = ( wt[index]<= W ) ? val[index]+solve( W-wt[index] , val , wt , dp , index-1) : INT_MIN;

        return dp[index][W] = max( take , notTake ); 
        
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int index = val.size(); 
        vector<vector<int>> dp( index , vector<int>(W+1 , -1)); 
        return solve( W , val , wt , dp , index-1 ); 
        
    }
};