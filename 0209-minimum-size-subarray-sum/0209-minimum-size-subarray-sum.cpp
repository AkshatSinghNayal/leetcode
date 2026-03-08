class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0 , mini = INT_MAX ,  right = 0 , n =  nums.size() ; 
        long long sum = 0 ; 

        while( right < n and left < n ){
            sum+=nums[right]; 
            
            while( left < n and sum>= target ){
                if( left <= right ){
                    mini = min( mini , right - left +1 ); 
                }
                sum-=nums[left]; 
                left++; 
            }

            right++; 
        }
        return (mini == INT_MAX ) ?  0 : mini; 
    }
};