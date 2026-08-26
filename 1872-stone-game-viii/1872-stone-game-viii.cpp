class Solution {
public:

    int stoneGameVIII(vector<int>& stones) {
        int n =stones.size(); 
        vector<int>prefix(n);
        prefix[0] = stones[0]; 
        vector<int>dp(n+1 ,0); 
        for(int i =1 ;i<n ;i++ ){
            prefix[i] = prefix[i-1]+stones[i]; 
        }
        dp[n-1] = prefix[n-1]; 
        for(int i  = n-1 ;i>=0 ;i-- ){
            if(i == n-1 ) continue; 

            int take = prefix[i]- dp[i+1]; 
            int notTake = dp[i+1]; 

            dp[i] = max(take , notTake ); 

        }
        return dp[1]; 
    }
};