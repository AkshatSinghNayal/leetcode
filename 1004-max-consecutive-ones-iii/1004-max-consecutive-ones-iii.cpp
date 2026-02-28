class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right = 0  , left=0; 
        int n  = nums.size(); 
        int temp = k ; 
        int maxi = 0 ; 
        while( right  < n and left < n ){
            if( nums[right] ==1 ) right++; 
            else if( temp> 0 and nums[right] == 0  ){
                temp-- ; 
                right++ ; 
            }
            else{
                while( left < n and temp ==  0 ){
                    if( nums[ left] == 0  ){
                        temp++; 
                    }
                    left++; 
                }
            }

            maxi = max( maxi , right-left); 

            
        }
        return maxi; 
    }
};