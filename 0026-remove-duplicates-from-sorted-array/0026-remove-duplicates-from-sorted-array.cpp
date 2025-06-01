class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0 ; int j = 0 ; int k = 0 ; 
        int previous = INT_MIN;
        while(i<nums.size()){
            if(nums[i] != previous){
                nums[j] = nums[i];
                j++; k++;
            }
            previous = nums[i]; 
            i++;
        }
        return k ; 

    }
};