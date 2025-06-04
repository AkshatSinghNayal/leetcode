class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans (n,0); int k = 0 ; 
        for( int i = 0  ; i<nums.size();  i++){
            if(nums[i] != 0 ){
                ans[k++] = nums[i];
            }
        }
        for(int i = 0 ; i<nums.size() ; i++){
            nums[i] = ans[i] ; 
        }
    }
};