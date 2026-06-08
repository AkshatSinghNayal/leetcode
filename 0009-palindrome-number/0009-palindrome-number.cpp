class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp = x; 
        int reverse = 0; 
        while(temp){
            reverse = reverse*10+(temp%10);
            temp/=10;            
        }
        return x == reverse;
    }
};