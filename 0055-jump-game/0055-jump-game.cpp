class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if(nums.size() == 1 ) return true;
        int index = 0 ; 
        int i  = 0 ; 
        int n  = nums.size() ; 
        while(i<n){
            // if(index == i && nums[i] ==0 ) return false ;
            if(index<i) return false ;
            if(index<i+nums[i]){
                index = i+nums[i]; 
            }
            if(index>=n-1) return true ;

            i++; 
        }
        return false; 
    }
};