class Solution {
public:
    int minimumFlips(int n) {
        int msb = 31 - __builtin_clz(n); 
        int k  = n ;
        string s  = "";
        for( int i = msb ; i>=0 ;i-- ){
            if( (1ll << i)&(n) ){
                s+='1';
            }
            else{
                s+='0'; 
            }
        }  
        string revStr = s ; 
        int operations = 0 ;
        reverse(revStr.begin(),revStr.end()); 
        for( int i = 0 ; i<s.size() ;i++){
            if( s[i] != revStr[i]) operations++;
        } 
        return operations ;
    }
};