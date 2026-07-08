class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n  = nums.size();
        // if( nums[0] == 0  ) return false; 
        int i = 0 , far = 0 , maxi = 0; 
        while(i<n){

            maxi = max(maxi ,nums[i]+i); 
            if( far == i ){
                far = maxi; 
                maxi =0; 
                if( far>=n-1 ) return true; 
            }
            
            i++; 

        }
        return false; 
    }
};