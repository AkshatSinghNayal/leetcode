class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n); 

        long long ans = 0 ; 
        long long sum = 0 ; 

        for( int i = 0 ; i<s.size() ; i++){
            char digit =  s[i]; 
            if( (digit-'0') !=0){
                ans = (ans*10 + (digit -'0')); 
                sum+=digit-'0'; 
            }
        }
        return (sum*ans) ; 
    }
};