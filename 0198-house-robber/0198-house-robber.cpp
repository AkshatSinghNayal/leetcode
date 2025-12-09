class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ; 
        int previous = nums[0] ; 
        int past =  0 ; 
        if( n ==1 ) return nums[0] ; 
        for( int i = 1 ; i<n ; i++ ){
            int take = nums[i] ; if( i>=2 ) take+= past ; 
            past = previous ;
            previous = ( take > previous  ) ? take : previous ; 
        }
        return previous ; 
    }
};