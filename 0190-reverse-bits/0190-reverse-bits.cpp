class Solution {
public:
    int reverseBits(int n) {
         uint32_t rev; 
          uint32_t temp = n ; 

          for( int i = 0 ; i<32 ; i++){
                rev<<=1 ; 
                rev = rev | (temp&1); 
                temp>>=1 ; 
          }
          return rev ;
    }
};