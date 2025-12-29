class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int row = 0;
        int col = m-1;

        int count = 0;
        while(row<n && col>=0){
            int val = grid[row][col];
            if(val<0){
                count+=(n-row);
                col--;
            }
            else{
                row++;
            }
        }
        return count;
    }
};