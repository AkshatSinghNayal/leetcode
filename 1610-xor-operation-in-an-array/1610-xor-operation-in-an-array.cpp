class Solution {
public:
    int xorOperation(int n, int start) {
        
        int xorr = start ; 
        int temp = start+2 ; 
        while(n>1){

            xorr=xorr^temp ; 


            temp+=2 ;
            n--; 
        }
        return xorr ; 
    }
};