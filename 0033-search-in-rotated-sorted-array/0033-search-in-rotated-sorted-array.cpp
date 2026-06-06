class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n  = nums.size(); 
        int start = 0 , end = n -1 , mid ; 
        while(start<=end){

            mid = start+(end-start)/2; 

            if(nums[mid]==target ) return mid ;

            if( nums[start] <= nums[mid] ){
                if( nums[start] <= target and target <= nums[mid]  ){
                    end = mid-1; 
                }
                else{
                    start =mid+1;
                }
            }
            else{
                if(nums[end]>= target and target>= nums[mid] ){
                    start = mid+1; 
                }
                else{
                    end = mid-1; 
                }
            }
        }
        return -1;
    }
};