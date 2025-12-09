class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); 
        if( n  == 1 ) return nums[0] ; 
        vector<int> maxi(n) , mini(n) ;
        maxi[0] = mini[0]=nums[0] ; 
        int ans  = nums[0];

        for( int i  =1 ; i<n ; i++){
            int x =  nums[i] ; 
            maxi[i] = max({x , x*maxi[i-1] , x*mini[i-1]}); 
            mini[i] = min({x, x*maxi[i-1] , x*mini[i-1]}) ; 
            ans = max(ans , maxi[i]); 
        }
        return ans ; 
    }
};