class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size() ; 
        int col = grid[0].size();
        int count = 0 ; 
        for(int i  = 0 ; i< row  ; i++){
            for(int j = col-1 ; j>=0 ; j--){
                if(grid[i][j]<0) count++; 
                else break;
            }
        }
        return count;
    }
};