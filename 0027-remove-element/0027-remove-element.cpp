class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0 ; int end = nums.size()-1; 
        int size = nums.size();
        while(start<=end){
            if( nums[start]== val){
                swap(nums[start], nums[end]); 
                end--;
                size--;
            }
            else{
                start++;
            }
        }
        return size ;
    }
};