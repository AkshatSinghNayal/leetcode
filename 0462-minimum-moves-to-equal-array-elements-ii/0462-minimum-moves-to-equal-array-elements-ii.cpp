class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n  = nums.size();
        sort(nums.begin(),nums.end());
        int mid = nums[(n-1)/2]; 
        int count = 0; 
        for(auto& it : nums ){
            count+=abs(it-mid); 
        }
        return count; 
    }
};