class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int i = 0  , count =0, maxJump = 0 , globalMaxJump = nums[0]  ; 
        while( i <n ){
            while( i < n and i<=globalMaxJump){
                maxJump = max( maxJump , i+nums[i]);
                if( i==globalMaxJump ){
                count++; 
                globalMaxJump = maxJump;
            }
                if( globalMaxJump >=n-1 ) return count+1;
                i++;
            }
            

        }   
        return -1;
    }
};