class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r = 0 , l = 0 , maxLen = 0 ; 
        int countZeros =0 ;
        while( r<nums.size()){
            if( nums[r] == 0 ){
                countZeros++;
            }
           
            if( countZeros>k){
                if(nums[l] == 0 ){
                    countZeros--;
                }
                
                l++;
                
            }
           if(countZeros<=k){
             int len = r-l+1;
            maxLen = max(maxLen,len);
           }
             r++;

        }
        return maxLen;
    }
};