class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int left = 0 , right= 0 ; 
        while(left < nums.size()  && nums[left]==0 ) left++ ;
        right = left+1 ; 

        while( right < nums.size()){
             while( right < nums.size() && nums[right]==0 ) right++; 
            int len= right-left+1 ; 

            
            if( len-k < k && nums[right] ==1  ){
                return false ; 
            }
            left = right ; 
            right++; 
        }

        return true; 
    }
};