class Solution {
public:
    int smallestNumber(int n) {
        int i = 2 ; 
        if(n<=1 ) return 1 ; 
        while(i<=n){
            i=i*2 ;
        }
        return i-1;
    }
};