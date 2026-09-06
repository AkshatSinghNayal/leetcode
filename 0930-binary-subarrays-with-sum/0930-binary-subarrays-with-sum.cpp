class Solution {
public:

    int atmost( vector<int>& nums , int goal ){
        long long sum = 0 , count = 0 ; 
        if(goal < 0 ) return 0;
        int left = 0  , right = 0 , n = nums.size() ; 

        while(right < n ){
            sum+=nums[right]; 

            while( left < n and sum>goal){
                sum-=nums[left]; 
                left++; 
            }

            count = count + ( right - left +1 );
            right++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost( nums , goal ) - atmost(nums,goal-1 ); 
    }
};