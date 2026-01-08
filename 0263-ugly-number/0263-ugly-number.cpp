class Solution {
public:
    bool isUgly(int n) {
        if (n ==1 ) return true; 
        if(n<=0 ) return false ; 

        for( auto& it : { 2, 3 ,5 }){
            while( n % it ==  0 ){
                n/=it ; 
            }
        }
        return n == 1 ;
    }
};