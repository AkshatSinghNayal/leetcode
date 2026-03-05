class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size() ;
        if( k ==  1 ) return 0;
        int left = 0 , right = 0  ; 
        int count = 0 ;
        long long product =  1;
        while( left < n and right < n ){
            product*=nums[right]; 
            while( left < n and product >= k ){
                product/=nums[left];
                left++;     
            }

            if( left <= right ) count+=( right - left +1 ); 
            right++;

        }
        return count ;
    }
};