class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long left =0 , right = 0 , n = nums.size(); 
        long long sum = 0 , count =0 ; 

        while( right < n ){

            sum+=nums[right]; 

            while( left <= right and (sum*(right-left+1))>=k){
                sum-=nums[left]; 
                left++; 
            }

            if( left <= right ) count+=(right-left+1 ); 

            right++; 
        }
        return count; 
    }
};