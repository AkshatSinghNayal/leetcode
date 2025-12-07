class Solution {
  public:
    
    int solve( vector<int>& height , vector<int>& dp , int index ){
        if( index == 0  ){
            return 0 ; 
        }
        
        if( dp[index]!=-1 ){
            return dp[index]; 
        }
        
        int left =  solve(height , dp , index -1 ) + abs( height[index] - height[index-1]) ; 
        int right = INT_MAX ; 
        if( index>1 ){
            right =  solve( height , dp , index-2 )  + abs(height[index] - height[index-2]) ; 
        }
        
        return dp[index]=min(left , right) ; 
    }
  
    int minCost(vector<int>& height) {
        // Code here
        int n =  height.size() ; 
        if( n  ==  1 ) return  0 ; 
        vector<int> dp(n,-1) ; 
       return  solve( height , dp , n-1 ) ; 
    }
};