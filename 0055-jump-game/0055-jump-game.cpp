class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i  = 0  ; 
        int n  = nums.size() ; 
        int jumpIdx =  0; 
        while( i< n ){
            int jump = nums[i]; 
            if( jump+i > jumpIdx ){
                jumpIdx = jump+i ;
                
            } 
            i++; 
            if(jumpIdx >=n-1 )return true; 
            else if( jumpIdx<i ) return false; 

        }
        return false; 
    }
};