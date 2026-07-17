class Solution {
public:

    pair<int,int> solve(vector<int>& nums,vector<vector<pair<int,int>>>&dp,int i, int prev , int n ){
        if( i>=n ) return {0,1}; 
        if(dp[i][prev+1].first != -1 ){
            return dp[i][prev+1];
        }

        pair<int,int> take = {-1e9 , 0}; 
        if( prev == -1 or nums[prev] < nums[i]){
            take = solve(nums , dp , i+1 , i , n ); 
            take.first++;
        }
        auto notTake = solve(nums,dp,i+1 ,prev , n ); 

        if(take.first > notTake.first ){
            return dp[i][prev+1] = take;
        }
        else if( take.first < notTake.first ){
            return dp[i][prev+1] = notTake;
        }

        return dp[i][prev+1] = { take.first , take.second+notTake.second}; 
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n+1 , {-1,-1})); 
        return solve(nums,dp,0,-1,n).second;
    }
};