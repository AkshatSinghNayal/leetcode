class Solution {
public:

     void reverse( string& s , int start , int end){
            
            while( start<end){
                swap(s[start++] , s[end--]);
            }

        }

    string reverseWords(string s) {
        int left = 0 ; int right = 0 ; 
       
       while(right<s.size()){
            
            if(s[right] == ' '){
                reverse( s , left , right-1);

                left=right+1;
            }
            if( right == s.size()-1 ){
                reverse( s , left , right);
            }

         right++;
       }

        return s ; 
        
    }
};