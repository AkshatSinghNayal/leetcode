class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int m =  wt.size(); 
        vector<int> prev(W+1,0), curr(W+1); 
        
        for( int i = wt[0] ; i<=W ; i++  ){
            prev[i] = val[0];
        }
        
        for( int i  =  1 ; i<m ; i++ ){
            for( int j = 1 ; (j<=W ) ; j++ ){
        curr[j] = (j >= wt[i]) ? max(val[i] + prev[j - wt[i]], prev[j]) : prev[j];
            }
            prev = curr ; 
        }
        return prev[W];
    }
};