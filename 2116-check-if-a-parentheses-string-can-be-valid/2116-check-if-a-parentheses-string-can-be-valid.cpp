class Solution {
public:
    bool canBeValid(string s, string locked) {
        int mini = 0  , maxi = 0  ; 
        int n = s.size(); 
        if (n % 2 != 0) return false;
        for(int i = 0 ; i< n ;i++ ){
            if( locked[i] =='1' and s[i] ==  '('){
                mini++;
                maxi++; 
            }
            else if( locked[i] == '1' and s[i] == ')'){
                mini--; 
                maxi--; 
            }
            else if( locked[i] == '0' ){
                mini--; 
                maxi++; 
            }
            if( maxi < 0 ) return false;
            if( mini < 0 ) mini = 0; 
        }
       
        return (mini == 0); 
    }
};