class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort( nums.begin() , nums.end() ,[&] (auto a , auto b ){
            int diff = abs(a-0 );
            int diff2 = abs(b-0);

            if( diff == diff2 ){
                return a > b ; 
            }
            return diff < diff2;

        });
        return nums[0]; 
    }
};