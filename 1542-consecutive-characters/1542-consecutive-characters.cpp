class Solution {
public:
    int maxPower(string s) {
        int maxLen = INT_MIN ;
        if (s.size() == 1) return 1; 
        int count = 1;  
        char c = s[0];
        for( int i = 1 ; i<s.size() ; i++){
            if( c != s[i]){
                c = s[i]; 
                count=1 ; 
            }
            else{
                count++;
            }
            maxLen = max( maxLen , count ) ; 
        }
        return maxLen ; 
    }
};