class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size() , m = mat[0].size();
        int shift = k%m ; 
        if( shift == 0  ) return true;
        for(int i = 0 ;i< n ;i=i+2){
            for(int j = 0 ; j< m ;j++ ){
                int index = (j-shift+m)%m;; 
                // if(index <0 ) index = m-index;
                if(mat[i][j] != mat[i][index]) return false;
            }
        }
        for(int i  = 1; i< n ;i=i+2){
            for(int j = 0 ; j< m ; j++ ){
                int index = (j+shift)%m; 
                if(mat[i][j] != mat[i][index]) return false;
            }
        }
        return true;
    }
};