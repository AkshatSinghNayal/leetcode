class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size() ; 
       
        int ones = 0;
        for( auto &it : nums){
            if( it == 1 ){
                ones++;
            }
        }
        if( ones >= 1){
            if( ones == nums.size()) return 0;
            return n-ones;
        }
        
        int length = INT_MAX ; 
        long long int gdc1;

        for( int i = 0 ;i<nums.size() ; i++){
            gdc1 = nums[i];
            for( int j = i+1 ; j<nums.size() ;j++){
               gdc1 = gcd(gdc1 , nums[j]); 
               if( gdc1 == 1 ){
                    length = min( length , j-i+1 ) ;
                    break ;
               }
            }
        }
        return ( length  == INT_MAX ) ? -1 : ( n+length - 2) ;




    }
};