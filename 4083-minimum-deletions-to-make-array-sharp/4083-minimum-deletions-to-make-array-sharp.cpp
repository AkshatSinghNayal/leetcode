class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int count =0 ; 
        int i = 0  , n = nums.size(); 
        while( i < n ){
            int j  = i+1;
            while( j<n and (nums[i]^nums[j]) == 0 ){
                j++; 
                count++; 
            }
            i=j;
        }
        return count;
    }
};