class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int peak = 0 ; 
        int waviness = 0 ;
        string s1 = to_string(num1); 
        string s = to_string(num2) ;

        for( int i  = num1 ; i<=num2 ; i++){
            string s = to_string(i); 
            for( int j  = 1 ; j<s.size()-1 ;j++){
                if( s[j] > s[j-1] && s[j]>s[j+1]) peak++;
                if(s[j]<s[j-1] && s[j]<s[j+1]) waviness++;
            }
            
        }
        return (peak+waviness);
    }
};