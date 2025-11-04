class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1; 
        if( n == 0 ) return ans ; 
        if( n == 1 ) return x ; 
        long long num =n; 
        if( num<0 ){
            x = 1/x ;
            num = -num; 
        }
        while( num > 0 ) {
            if( num % 2== 0 ){
                x = x * x ; 
                num/=2 ; 
            }
            else{
                ans=ans*x ; 
                num=num-1; 
            }
        }
        return ans; 
    }
};