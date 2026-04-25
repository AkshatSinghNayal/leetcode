class Solution {
public:
    bool validDigit(int n, int x) {
        int digit = (n == 0) ? 1 : log10(abs(n)) + 1;
        bool found = false;
        while(digit--){
            int temp = n%10; 
            if( digit == 0 and x == temp ) return false;
            if( temp == x ) found = true; 
            n/=10; 
        }
        return ( found ) ? true : false;
    }
};