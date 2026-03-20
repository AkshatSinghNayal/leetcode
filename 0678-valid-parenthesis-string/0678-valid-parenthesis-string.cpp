class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0  , maxi = 0 ;
        

        for(auto& it : s ){
            if( it == '(' ){
                mini++; 
                maxi++; 
            }
            else if( it == ')'){
                mini--; 
                maxi--; 
            }
            else{
                mini--;
                maxi++; 
            }

            if( maxi < 0 ) return false ; 
            if( mini < 0 ) mini = 0 ; 
        }
        return mini == 0; 
    }
};