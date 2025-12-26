class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); 
        if( n  == 1 ) return nums[0] ; 
        int currentMax =  nums[0]; 
        int currentMin = nums[0] ; 
        int ans =  nums[0]; 
       
       

        for( int i  =1 ; i<n ; i++){
            int x =  nums[i] ; 
           int maxi = max({x , x*currentMax , x*currentMin}); 
           int mini = min({x, x*currentMax , x*currentMin}) ; 
            
            currentMax = maxi ; 
            currentMin = mini ; 

            ans = max(ans , currentMax ); 
        }
        return ans ; 
    }
};