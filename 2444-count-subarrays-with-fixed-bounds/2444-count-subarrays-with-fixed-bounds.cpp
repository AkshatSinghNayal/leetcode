class Solution {
public:

    long long atmost(vector<int>&nums,int minK, int maxK){
        int left = 0 , right = 0; 
        long long count =0 ; 
        int n  = nums.size(); 

        // if(minK ==0 or maxK == 0 ) return 0;

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

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        return atmost(nums, minK, maxK)- atmost(nums, minK + 1, maxK)- atmost(nums, minK, maxK - 1)+ atmost(nums, minK + 1, maxK - 1);
    }
};