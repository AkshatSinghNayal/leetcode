class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0 ; 
        int r = 0 , l= 0 ; 
        while(r < nums.size()){
            if(nums[r] == 0 ){
                l=r+1;
            }


            int len = r-l+1 ; 
            maxLen = max ( maxLen , len );
            r++;

        }
        return maxLen;
    }
};