class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size() ; 
        if(n == 1 ) return true; 
        int left = 0  , right = n -1; 
        bool first = true;

        while( left<right ){

            if( s[left] !=s[right]  ){
                if( left+1 < n && s[left+1] == s[right] && first ){
                    left++; 
                    first = false;
                }
                else if( right-1>=0 && s[right-1] == s[left] && first){
                    right--; 
                    first=false ;
                }
                else{
                    return false;
                }
            }
            

            left++ ; right-- ; 

        }
        return true;
    }
};