class Solution {
public:
    string largestEven(string s) {
        int n  = s.size() ; 
        string  ans = "" ; 
        for( int i = n-1 ; i>=0 ; i--){
            if( s[i] ==  '2'){
                int len = i-0+1; 
                ans = s.substr(0 , len ) ; 
                break; 
            }
        }
        return ans; 
    }
};