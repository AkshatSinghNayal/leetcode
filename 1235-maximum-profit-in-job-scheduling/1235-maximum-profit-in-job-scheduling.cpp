class Solution {
public:

    int solve(vector<vector<int>>& temp, vector<int>&dp , int i , int n  ){
        if( i >= n ) return 0 ; 
        if(dp[i] != -1 ) return dp[i]; 

        int next = lower_bound(temp.begin()+i+1 , temp.end() , vector<int>{temp[i][1] ,0,0}) - temp.begin(); 

        int take = temp[i][2]+solve(temp ,dp , next , n ); 
        int notTake = solve(temp , dp , i+1 , n ); 
        
        return dp[i] = max(take , notTake); 
    }

    int jobScheduling(vector<int>& S, vector<int>& E, vector<int>& profit) {
        int n = S.size(); 
        vector<int>dp(n, -1 ); 
        vector<vector<int>> temp; 
        for(int i  = 0 ; i<n ;i++ ){
            temp.push_back({S[i] , E[i] , profit[i]}); 
        }
        sort(temp.begin() , temp.end());

        return solve( temp ,dp , 0 , n ); 

    }   
};