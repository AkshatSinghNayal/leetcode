class Solution {
public:

    int solve(vector<int>& stones,  vector<vector<int>>&dp , int i , bool player , int n ){
        if( i>=n ) return 0 ; 
        if( dp[i][player] != INT_MIN ) return dp[i][player]; 
        int maxi = INT_MIN; int mini = INT_MAX ; 
        if(player){
            int total = 0;
            for(int idx = 0 ;idx+i<n and idx < 3  ;idx++ ){
                int index = idx+i; 
                total+=stones[index]; 
                int sum = total + solve( stones , dp , index+1 , 1-player , n ); 
                maxi = max(maxi , sum ); 
            }
            return dp[i][player] = maxi ; 
        }
        else{
            for(int  idx = 0 ; idx+i < n and idx < 3 ; idx++ ){
                int index  = idx+i; 
                int sum =  solve( stones , dp , index+1 , 1-player , n ) ; 
                mini = min(mini , sum); 
            }
            return dp[i][player] = mini; 
        }
        return -1 ; 
    }


    string stoneGameIII(vector<int>& stones) {
        int n = stones.size(); 
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
        long long ans  =  solve( stones , dp , 0 , 1, stones.size() ); 
        long long total = accumulate( stones.begin() , stones.end() , 0LL ); 
        long long final = ans*2; 
        if( final== total ){
            return "Tie"; 
        }
        else if( final > total ){
            return "Alice"; 
        }
        return "Bob"; 
    }
};