class Solution {
public:
    int numSub(string s) {
        long long count = 0 ;  
        const int MOD = 1e9 + 7 ; 
        int left = 0 , right =0 ; 

        while( s[left] =='0') left++; 
        right = left ; 

        while( right < s.size()) {

            if(s[right] == '0'){
            while(s[right] =='0') right++; 
            left = right ; 

            }
            
            while( s[right] == '1' && right<s.size()){
                right++; 
            }

            long long len = (right-1)-left+1 ;

            count += (len * (len + 1) / 2) % MOD;
            
        }
        return int(count) ;
    }
};