class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if (n == 0) return 1;
        if( n==1 )return 10 ; 
       int  ans = 10;
       int eleFormation =9 ; 
        
        for( int i = 1; i<n ; i++){
            
            eleFormation=eleFormation*(10-i); 

            ans+=eleFormation ; 
        }
        return ans ; 
    }
};