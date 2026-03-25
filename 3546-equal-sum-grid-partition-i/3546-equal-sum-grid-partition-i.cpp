class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size()  , m = grid[0].size();
        long long total = 0; 
        vector<long long> row(n) ;  vector<long long> col(m); 
        
        
        for(int i = 0 ; i< n ;i++ ){
            row[i] = accumulate(grid[i].begin(), grid[i].end() , 0LL);
            total+=row[i]; 
        }
        for( int i = 0 ; i< m ; i++ ){
            long long temp = 0; 
            for(int j = 0 ; j< n ;j++ ){
                temp+= grid[j][i]; 
            }
            col[i] = temp;
            
        }

        if(total%2 != 0 ) return false;
        long long temp1 = total / 2;

        for( int i = 0 ; i< n; i++ ){
            temp1-=row[i]; 
            if(temp1 == 0  ) return true;
            if( temp1< 0 ) break;
        }

        temp1 = total/2; 

        for(int i  = 0 ;i< m ;i++ ){
            temp1-=col[i]; 
            if( temp1 == 0 ) return true; 
            if( temp1< 0 ) break;
        }
        return false;
    }
};