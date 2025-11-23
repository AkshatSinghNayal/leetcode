class Solution {
public:

    bool check( string& s , int left , int right ){
        while( left < right ){
            if( s[left++] != s[right-- ]) return false ;
        }
        return true; 
    }

    bool validPalindrome(string s) {
        bool first = true; 
        int n = s.size() ; 
        int left = 0  , right = n-1 ; 
        while( left < right ){
            if( s[left] !=s[right]  && first ) {
            return check( s, left+1 , right ) || check( s , left , right-1 ) ; 
                
            }
            left++ ; right--; 
        }
        return true;
    }
};