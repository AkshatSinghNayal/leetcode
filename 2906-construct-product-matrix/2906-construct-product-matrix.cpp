class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n  = grid.size() , m = grid[0].size();
        vector<long long>ans(n*m);  
        vector<long long>suffix(n*m);
        vector<long long>nums(n*m);
        int index= 0; 
        for(int i = 0; i< n;i++ ){
            for(int j = 0 ; j< m ; j++ ){
                nums[index++] = grid[i][j]; 
            }
        }
        suffix[n*m-1] = 1 ; 
        for(int i = n*m-2 ; i>=0 ;i-- ){
            suffix[i] = (suffix[i+1] * nums[i+1]) % MOD;
        }
        int prefix = 1; 
        for(int i = 0 ;i< n*m ;i++ ){
            ans[i] = (prefix*suffix[i])%MOD;
            prefix = (prefix * nums[i]) % MOD;
        }
         index=0; 
        for(int i = 0 ;i< n; i++ ){
            for(int j  = 0; j< m ;j++ ){
                grid[i][j] = ans[index++]; 
            }
        }
        return grid;    
    }
};