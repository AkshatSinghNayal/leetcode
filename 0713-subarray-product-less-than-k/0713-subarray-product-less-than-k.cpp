class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count= 0  ; 
        if( k  ==  1 ) return 0 ;
        int n  = nums.size()  ; 
        int totalMul=1 ; 
        int left= 0 , right= 0;
        while( right < n ){
            totalMul *= nums[right] ;
            while(  left < n && totalMul >= k ){
                totalMul/=nums[left]; 
                left++; 
            }
            if( totalMul < k ){
                count+= right-left +1 ; 
            }
            right++ ;
        }

        return count ; 
    }
};