class Solution {
public:

    int solve( vector<int>& dp , vector<int>& prefix , int i , int n ){
        //base
        if( i == n -1 ) return prefix[i]; 

        if(dp[i] != INT_MIN ) return dp[i]; 
        int take = prefix[i] - solve( dp , prefix , i+1 , n );
        int notTake = solve(dp , prefix , i+1 , n ); 


        return dp[i]=  max(take, notTake ); 
    }

    int stoneGameVIII(vector<int>& stones) {
        int n =stones.size(); 
        vector<int>prefix(n);
        prefix[0] = stones[0]; 
        vector<int>dp(n ,INT_MIN); 
        for(int i =1 ;i<n ;i++ ){
            prefix[i] = prefix[i-1]+stones[i]; 
        }
        return solve( dp , prefix , 1 , n ); 
    }
};