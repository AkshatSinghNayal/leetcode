class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size() ; 
      
       int cnt1 = 0;
        for (int i = 0; i < n; ++i)
            cnt1 += (nums[i] == 1);
        if (cnt1)
            return n - cnt1;
        int result = INT_MAX ; 
        for( int i  = 0 ; i<n ; i++){
            int element = nums[i];
            for( int j= i+1 ; j<n ; j++){
                element = gcd( element , nums[j]); 
                if( element == 1 ) {
                    result = min( result  , (j-i)+1 );
                    break; 
                }
            }
        }
        return ( result  == INT_MAX ) ? -1: result +n-2 ;

    }
};