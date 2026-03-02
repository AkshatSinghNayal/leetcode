class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); 
        if( n  == 1 ) return nums[0] ; 
        int maxi =  nums[0]; 
        int mini = nums[0] ; 
        int ans =  nums[0]; 
       
       

        for( int i  =1 ; i<n ; i++){
            int x =  nums[i] ; 
            maxi = max({x , x*maxi , x*mini}); 
            mini = min({x, x*maxi , x*mini}) ; 
            
            // currentMax = maxi ; 
            // currentMin = mini ; 

            ans = max(ans , maxi ); 
        }
        return ans ; 
    }
};