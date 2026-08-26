class Solution {
public:
    int dp[21][21][2]; 

    int solve( vector<int>& nums , int i , bool player , int n ){
        //base 
        if( i>=n ) return 0 ; 

        if( dp[i][n][player] !=-1 ) return dp[i][n][player]; 

        int maxi =  INT_MIN; 

        if( player ){
            int front = nums[i]+solve(nums, i+1 , 1-player , n ); 
            int back = nums[n-1]+solve(nums , i , 1-player , n-1 ); 

            maxi = max({  front , back }); 
        } 
        else{
            int front = solve(nums, i+1 , 1-player , n ); 
            int back = solve(nums , i , 1-player , n -1 ); 

            maxi  = min({  front , back }) ; 
        }

        return dp[i][n][player] = maxi ; 

    }


    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp)); 
        int n = nums.size(); 
        long long ans  = solve(nums , 0, 1 , n ); 
        long long total = accumulate( nums.begin() , nums.end() , 0LL ); 
        cout<< ans ; 
        return ( ans*2 >= total ); 
    }
};