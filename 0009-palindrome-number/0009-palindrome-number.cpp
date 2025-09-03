class Solution {
public:
    bool isPalindrome(int ini) {
        int x = ini;
        if(x<0) return false ; 
        long long sum = 0 ; 
        while( x!=0){
            sum = 1ll*sum*10 +(x%10);
            x=x/10;
        }
        return ini == sum ? true : false ;
    }
};