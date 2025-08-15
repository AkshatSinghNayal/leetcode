class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        long long value = 1 ; 
        while(value<n){
            value=value*4;
        }
        return value==n;
    }
};