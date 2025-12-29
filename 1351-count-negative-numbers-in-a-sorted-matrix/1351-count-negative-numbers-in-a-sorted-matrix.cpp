class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int row = 0;
        int col = m-1;

        int count = 0;
        while( row<n and col>= 0 ){
            int value = grid[row][col]; 
            if( value < 0 ){
                count+=n-row ; 
                col--; 
            }
            else row++; 
        }
        return count; 
    }
};