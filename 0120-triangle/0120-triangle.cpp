class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); 
        int size = triangle[n-1].size(); 
        vector<int>prev(size  , 1e8 ); 
        prev[0]=triangle[0][0]; 
        for( int i  =1 ; i<n ; i++){
            vector<int> temp(size,1e8);
            for(int j = 0; j<=i; j++){
                int up = (j<i) ? prev[j] : 1e8 ; 
                int left = (j-1>=0) ?  prev[j-1] : 1e8 ; 
                temp[j]=triangle[i][j]+ min( up ,left ); 
            }
            prev = temp ; 
        }
        int maxi = *min_element( prev.begin(),prev.end()); 
        return maxi ; 
    }
};