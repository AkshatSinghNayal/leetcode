class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n  =  grid[0].size(); 
        int m = grid.size(); 
        vector<long long> prev(n); 
        prev[0] = grid[0][0]; 
        for( int i  = 1 ; i< n ; i++) prev[i] = prev[i-1]+grid[0][i]; 

        for( int i = 1; i< m ; i++){
            vector<long long> current(n); 
            for( int j = 0 ; j< n ; j++){
                if( j == 0 ) current[j] = grid[i][j] + prev[j]; 
                else{
                    int temp =grid[i][j]; 
                    current[j] = (temp+prev[j] < current[j-1]+temp) ? temp+prev[j] : current[j-1]+temp;
                }
            }
            prev = current ; 
        }
        long long ans = prev[n-1]; 
        return (int)ans;
    }
};