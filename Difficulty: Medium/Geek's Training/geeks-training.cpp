class Solution {
  public:
    
    int solve( vector<vector<int>>& arr , vector<vector<int>>&dp , int last , int n  ){
        if( n  == 0 ){
            int maxi = INT_MIN; 
            int i  = 0 ; 
            while( i < 3 ){
                if( i != last ){
                    maxi =  max( maxi , arr[0][i]); 
                }
                i++; 
            }
            return maxi ;
        }
        
        if( dp[n][last] != -1 ){
            return dp[n][last]; 
        }
        int maxi = INT_MIN ; 
        for( int i  = 0  ; i< 3 ; i++){
           if( i != last ){
                int result = arr[n][i]+solve( arr ,dp , i , n-1);
           maxi = max( maxi , result ) ; 
           }
        }
       return dp[n][last] = maxi ; 
    }
  
    int maximumPoints(vector<vector<int>>& arr) {
        int n =  arr.size();
        vector<vector<int>> dp(n , vector<int>(4,-1)); 
       return solve( arr , dp ,3 , n-1 ) ; 
        
    }
};    