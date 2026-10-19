class Solution {
public:
    bool checkString(string s) {
        int n = s.size(); 
        int  i =0 , counta = 0 ; 
        while( i < n and s[i] == 'a'){
            counta++ ; 
            i++;
        }
        if( i>=n ) return true;
        int check = counta;

        while( i<n ){
            if( s[i]== 'a') counta--; 
            if( check != counta ) return false;
            i++; 
        }
        return true;
    }
};