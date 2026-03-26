class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0 , right = 0 , maxi = n+1; 
        long long total=0; 
        while( right < n ){
            int ele = nums[right]; 

            total+=ele;

            while( left < n and total>=target){
                maxi = min(maxi , right-left+1);
                total-=nums[left];
                left++; 
            }

            right++; 
        }
        return ( maxi == n+1 ) ? 0 : maxi; 
    }
};