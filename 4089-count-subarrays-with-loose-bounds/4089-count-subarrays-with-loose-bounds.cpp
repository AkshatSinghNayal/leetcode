class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int left = 0 , right = 0; 
        long long count =0 ; 
        int n  = nums.size(); 
        
        while(right<n){

            if( nums[right] < minK or nums[right] > maxK ){
                left = right+1;
                // continue;
            }

            if(left <= right ) count = count+ ( right - left +1 );
            right++; 
        }
        // cout << count ; 
        return count;
    }
};