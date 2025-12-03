class Solution {
  public:
  
    int minCost(vector<int>& height) {
        int n = height.size() ; 
        if( n  == 1 ) return 0 ; 
        
        int prev1 = 0 ;
        int prev2 = 0 ; 
        
        for( int i  = 1 ; i<n ; i++){
            int left =  prev1 + abs(height[i] - height[i-1]);
            int right = INT_MAX ;  
             if (i>1)
              {
                  right = prev2 + abs( height[i] - height[i-2]);
              }
              
            prev2 = prev1 ; 
            
            
        } prev1 =  min( left , right ) ;
            
        
        return prev1 ;
    }   
};
