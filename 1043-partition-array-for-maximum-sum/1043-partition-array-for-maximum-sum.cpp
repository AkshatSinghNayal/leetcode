class Solution {
public:
    int dp[501]; 
    
    int solve( vector<int>& arr , int i , int k , int n ){
        //base 
        if( i>=n ) return  0; 

        if(dp[i] != -1 ) return dp[i]; 

        int maxi = INT_MIN; 
        int maxVal = INT_MIN;

        for(int idx = i; idx-i+1 <= k and idx<n ; idx++ ){
            maxi = max(maxi , arr[idx]); 
            maxVal = max(maxVal , (idx-i+1)*maxi + solve(arr , idx+1, k , n )) ; 
        }

        return dp[i]=maxVal;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp)); 

        return solve( arr , 0 , k , arr.size() );
    }
};