class Solution {
public:
    bool isPalindrome(int x) {
       string s = to_string(x); 
       int left = 0 ; 
       int right = s.size()-1; 
       while(right<s.size()){
         if(s[left++]!=s[right--]){
            return false; 
         }
       } 
       return true;
    }
};