class Solution {
public:
    int maximum69Number (int num) {
       
       string s= to_string(num) ;
       bool found =  false; 
       for( int i  = 0 ; i<s.size() ; i++){
            if( s[i] ==  '6'){
                found = true; 
                s[i] = '9' ; 
                break ; 
            }
       }

        if( found ){
            int temp = stoi(s); 
            return temp ; 
        }
        return num ; 
    }
};