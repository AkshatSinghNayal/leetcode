class Solution {
public:

    // int solve(vector<int>nums ,vector<vector<int>>&dp , int i , int target ){
    //     //base
    //     if( i == 0  ){
    //         return ( target%nums[i] == 0  ) ? target/nums[i] : 1e7; 
    //     }

    //     if(dp[i][target] != -1 ) return dp[i][target]; 

    //     int take = ( target>= nums[i]) ? 1+ solve(nums, dp, i , target - nums[i]) : 1e7 ; 
    //     int notTake = solve( nums , dp ,i-1 , target ); 

    //     return dp[i][target] = min(take,notTake); 
    // }

    int numSquares(int n) {
        int count = 0; 
        for(int i =1 ;i*i<=n ;i++ ){
            count++; 
        }
        vector<int>nums(count);
        for(int i  =1 ; i<= count ; i++ ){
            nums[i-1] = i*i; 
        }
        vector<vector<int>>dp(count,vector<int>(n+1 , 0)); 
        
        for(int i  = 0;i<=n ; i++ ){
            if( i%nums[0] == 0  ) {
                dp[0][i] = i/nums[0];
            }
            
        }

        for(int i  = 1 ; i<count ; i++ ){
            for(int target = 1; target<=n; target++ ){
                int take = ( target>= nums[i]) ? 1+ dp[i][target - nums[i]] : 1e7 ; 
                int notTake = dp[i-1][target]; 
                dp[i][target] = min(take,notTake); 
            }
        }

        // for(auto& it : dp ){
        //     for(int i  = 0; i<n ;i++ ){
        //         cout<<it[i]  << " "; 
        //     }
        //     cout<<endl;
        // }


        return dp[count-1][n] ; 

    }
};