class Solution {
public:

    int atmost(vector<int>& nums , int goal){
        int left =  0; int count = 0 ;
        int sum = 0 ;
        if( goal < 0 ) return 0 ;
        for( int right = 0 ; right<nums.size() ; right++){
            sum+=nums[right];
           while( sum > goal){
                sum-=nums[left];
                left++;
            }

            if( sum<= goal){
                count+=right-left+1;
            }
        }
            return count;
    }


    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return atmost(nums , goal)-atmost(nums , goal-1);
    }
};