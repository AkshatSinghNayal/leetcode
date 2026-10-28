class Solution {
public:

    int atmostSmaller(vector<int>& nums, int target ){
        int left =0 , right =0 , n = nums.size(); 
        long long count = 0; 

        while(right<n){

            while( right < n and nums[right] >= target ){
                right++;
                left=right;
            }    

            if( right < n and left <= right ) count+=(right-left+1); 
            right++; 
        }
        return count;
    }

    int atmostGreater(vector<int>& nums , int target){
        int n = nums.size();
        return 1LL*n*(n+1)/2 - atmostSmaller(nums, target+1);   // all elements < target+1
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size(); 
        return (1LL*n*(n+1)/2)-(atmostSmaller(nums , left )+atmostGreater(nums,right));
    }
};