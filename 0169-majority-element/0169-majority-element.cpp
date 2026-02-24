class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0]; 
    int count = 1 ; 
    int n = nums.size() ; 
    for(int i = 1 ; i< n; i++ ){
        if( majority == nums[i]) count++; 
        else {
            count--; 
            if( count ==  0 ){
                majority = nums[i]; 
                count = 1; 
            }
        }
    }
    return majority ; 
    }
};