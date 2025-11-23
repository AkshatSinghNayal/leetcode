class Solution {
public:

    bool check( int row , int col , vector<vector<int>>& ans , int n ){
        // case 1 : upper side 

        for( int i =row ;i>= 0 ;i--){
            if(ans[i][col] == 1 ) return false ;
        }

        // case 2: diagonal left : 
        for( int i = row , j = col ; i>=0 && j>=0 ; i--, j--){
            if(ans[i][j] ==1 ) return false; 
        }

        // case 3 right diagonal : 
        for( int i = row , j =col ; i>=0 && j<n ; i--,j++){
            if(ans[i][j] ==1 ) return false;
        }

        return true; 
    }

    int helperFunction( int n , vector<vector<int>>& ans , int row , int count ){
        
        if( row  == n ) {
           return count+=1 ; 
        }

        for( int col = 0 ; col<n ; col++){
           if (check( row , col , ans , n )){
                ans[row][col] = 1; 
             count =   helperFunction( n , ans , row+1 , count); 
                ans[row][col] = 0; 
            }
        }
        return count ; 
    }

    int totalNQueens(int n) {
        if( n ==1 ) return 1 ; 
        vector<vector<int>> ans(n ,vector<int>(n,0)); 
       return helperFunction( n , ans, 0 , 0   ) ; 
    }
};