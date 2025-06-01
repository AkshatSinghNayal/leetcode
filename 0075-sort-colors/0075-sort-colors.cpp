class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left= 0 ; int mid = 0 ; 
        int high = nums.size()-1;
        while(mid<= high){
            if(nums[mid] == 0){
                swap(nums[left] ,nums[mid]);
                left++; 
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[high],nums[mid]);
                high--;
            }
            else{
                mid++;
            }
        }
    }
}; 