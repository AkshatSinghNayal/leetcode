class Solution {
public:
    vector<int> sortByBits(vector<int>& nums) {
        sort(nums.begin() , nums.end() , [&]( int a , int b ){
            int bitsOfA = __builtin_popcount(a);
            int bitsOfB = __builtin_popcount(b); 

            if( bitsOfA == bitsOfB ){
                return a < b ;
            }
            return bitsOfA < bitsOfB; 
        }); 
        return nums;
    }
};