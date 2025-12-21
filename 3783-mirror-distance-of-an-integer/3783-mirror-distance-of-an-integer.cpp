class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n ; 
       int number = 0 ; 
        while( temp ){
            number = (number*10)+temp%10; 
            temp/=10; 
        }
        return abs( n - number ); 
    }
};