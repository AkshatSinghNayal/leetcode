class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int threes = 0 ;
        int n = nums.size() ;
        for( auto &it : nums){
            if( it%3 == 0 ) threes++;
        }

         return n-threes ;

        

    }
};