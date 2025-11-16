class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0 ; 

        int left = 0 , right = 0 ; 

            while( left < nums.size() && nums[left] != 0 ) left++; 
            right = left ; 
       while( right < nums.size()){

            while( right< nums.size() && nums[right] != 0  ) right++; 
            left= right;  
            while( right< nums.size() && nums[right] == 0 ) right++ ; 

            long long len = right - left ; 

            count+=( len * (len + 1 )/2 ); 



       }
            return count ; 
    }
};