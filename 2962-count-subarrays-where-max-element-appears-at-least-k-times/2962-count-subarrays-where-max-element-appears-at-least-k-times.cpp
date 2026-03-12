class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long target = *max_element(nums.begin() , nums.end()); 

        int n = nums.size();
        int count = 0;
        long long ans = 0 ;  
        int left  = 0 , right = 0  ; 
        while( right <  n){
            
            if( nums[right] == target ) count++; 

            while( left <= right and count>=k){
                
                ans+= n-right;
                if( nums[left] == target ) count--; 
                left++; 
            }


            right++; 
        }
        return ans; 
    }
};