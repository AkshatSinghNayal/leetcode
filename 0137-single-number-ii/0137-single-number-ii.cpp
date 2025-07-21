class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0 ; 
        for( int i = 0 ; i <=31 ; i++){
            int countBits = 0; 
            
            for( auto it : nums ) {
                if(it&(1<<i)){
                    countBits++;
                }
            }
            if(countBits%3!=0){
                result = result | (1<<i);
            }
        }
        return result ; 
    }
};