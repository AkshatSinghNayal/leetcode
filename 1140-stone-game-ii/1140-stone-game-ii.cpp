class Solution {
public:

    int dp[101][101][2]; 

    int solve( vector<int>& piles , int i , int m , int n , int player ){
        //base ;

        if(i>=n ) return 0 ;  

        if(dp[i][m][player] != -1 ) return dp[i][m][player]; 

        int maxi = INT_MIN; int mini = INT_MAX; 

        if( player ){
            long long total = 0 ;
            for(int X = 0 ; X+i < n and X <2*m;  X++ ){
                int index = X+i; 
                total+=piles[index]; 
                int sum = total + solve( piles , index+1 , max(m,X+1), n , 1-player);
                maxi = max( maxi , sum ); 
            }
            return dp[i][m][player] = maxi;
        }
        else{
            for(int X = 0 ;X+i<n and X <2*m ; X++ ){
                int index=  X+i;
                int sum = solve(piles , index+1 , max(m,X+1) , n , 1-player ); 
                mini = min( mini, sum ); 
            }
            return dp[i][m][player] = mini;
        }
        return  -1; 
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp)); 
        return solve( piles , 0,1 , piles.size() , 1 ); 
    }
};