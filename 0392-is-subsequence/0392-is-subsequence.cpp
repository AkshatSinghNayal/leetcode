class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size() ; 
        int m=t.size() ; 
        if( n > m ) return false;
        string result = "" ; 

        int i = 0 , j = 0 ; 
        while( i < n and j < m ){
            if( s[i] != t[j]){
                j++; 
            }
            else{
                result+=s[i]; 
                i++ ; j++; 
            }
        }
        return (result == s ); 
    }
};