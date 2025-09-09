class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xORR = 0 ;
        for( auto it : nums){
            xORR^=it ; 
        }
        int difference = xORR&-(long long)xORR; 
        int bucket1 = 0 , bucket2  = 0; 
        for ( int i  = 0 ; i< nums.size() ; i++){
            if( (nums[i] & difference) != 0 ){
                bucket1^=nums[i]; 
            }
            else{
                bucket2^=nums[i];
            }
        }
        return {bucket1,bucket2};
    }
};