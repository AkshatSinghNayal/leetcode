class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        
        sort(nums.begin(),nums.end()); 
        int i = 0; 
        while(i<nums.size()){

            if(i+1 < nums.size()){
                swap(nums[i],nums[i+1]); 
                i++; 
            }
            i++; 
        }
        return nums; 
    }
};