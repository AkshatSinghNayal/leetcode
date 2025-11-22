class Solution {
public:
    int minimumFlips(int n) {
        string revStr =""; 
        int k  = n ; 
        while(k!=0){
            revStr.push_back((k&1)+'0');
            k>>=1;
        }
        int count = 0;
        reverse(revStr.begin(),revStr.end()); 
        k = n; 
        for( int i  = 0  ; i<revStr.size() ; i++){
            if( (k&1) != revStr[i]-'0') count++;
            k>>=1 ;
        }
        return count;
    }
};