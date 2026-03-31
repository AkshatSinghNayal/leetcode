class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n  = nums.size();
        int i = 0 , maxJump= 0  ; 
        while( i < n ){

            maxJump = max( maxJump , i+nums[i]);
            if( maxJump >= n-1 ) return true;
            if( maxJump <= i ) return false;
            i++;
            
        }
        return false;
    }
};