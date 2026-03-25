class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        for(auto& it : grid ){
            total+=accumulate(it.begin(),it.end(),0LL);
        }
        if(total%2 != 0 ) return false;
        long long temp = total/2;
        for(auto& it : grid ){
            temp -= accumulate(it.begin(),it.end(),0LL); 
            if( temp == 0  ) return true;
            if(temp<0 ) break;
        }
        temp = total/2;
        int m = grid[0].size() , n = grid.size();
        for( int i = 0 ;i<m ;i++ ){
            for(int j = 0 ; j< n ;j++ ){
                temp-=grid[j][i]; 
            }
            if( temp == 0  ) return true;
            if( temp<0 ) return false;
        }
        return false;
    }
};