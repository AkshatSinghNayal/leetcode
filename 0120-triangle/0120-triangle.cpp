class Solution {
public:

    int solve(vector<vector<int>>& triangle , vector<vector<int>>& dp , int row , int col , int size ){

        if( col <0 or col>= size  )return 1e9; 
        
        if( row == 0 ) return triangle[row][col]; 

        if( dp[row][col]  != -1 ) return dp[row][col]; 

        int up = ( row-1>= 0 ) ? solve( triangle , dp , row-1 , col , triangle[row-1].size()) : 1e9 ;
        int left =  ( row-1>= 0 ) ? solve( triangle , dp , row-1 , col-1 , triangle[row-1].size()) : 1e9;      

        return dp[row][col] = triangle[row][col] + min(up, left);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size(); 
        if( row ==  1 ) {
            int maxi = accumulate(triangle[0].begin(),triangle[0].end(),0); 
            return maxi;
        }
        int col = triangle[row-1].size(); 
        vector<vector<int>> dp ( row , vector<int>(col, -1)); 
        int result = INT_MAX ;
        int size= (row-2>=0 ) ? triangle[row-1].size() : 0 ; 
        for( int i = 0 ; i<col ; i++){
            result = min( { result , solve(triangle , dp , row-1 , i  , size)}); 
        }
        return result ; 
    }
};