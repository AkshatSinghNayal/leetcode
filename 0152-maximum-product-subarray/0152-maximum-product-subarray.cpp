class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long product  =  1; 
        int n = nums.size() ; 
        long long maxi  = INT_MIN; 
        for( int i = 0 ; i< n ; i++){
            product*=nums[i]; 
            maxi = ( maxi < product ) ? product : maxi ; 
            if( product == 0 ) product = 1; 
        }
        product = 1; 
        for( int i = n-1 ; i>= 0 ; i-- ){
            product*=nums[i]; 
            maxi = max( maxi , product ) ; 
            if( product == 0 ) product  =1 ; 
        }
        return maxi ; 
    }
};