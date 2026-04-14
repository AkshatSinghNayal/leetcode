class Solution {
public:

    int findTargetSumWays(vector<int>& arr, int diff) {
        int n  = arr.size(); 
        int sum = accumulate(arr.begin() , arr.end() , 0); 
        if ((sum - diff) < 0 || (sum - diff) % 2 != 0) return 0;
        int target = (sum-diff)/2;
        vector<vector<int>>dp( n+1 , vector<int>(target+1 ,0)); 
        
        dp[0][0] = 1; 


        for(int i = 1; i<= n ; i++ ){
            for(int j= 0; j<= target ; j++ ){
                int take = 0; 
                if( j >= arr[i-1]){
                    take =dp[i-1][j-arr[i-1]];  
                }
                int notTake = dp[i-1][j]; 


                dp[i][j] = (take + notTake ); 
            }
        }
        return dp[n][target]; 
    }
};