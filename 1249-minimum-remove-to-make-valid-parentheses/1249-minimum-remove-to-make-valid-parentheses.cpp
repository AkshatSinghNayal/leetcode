class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0 ; 
        string result =""; 
        for(auto& it : s ){
            if( it == '(') {
                count++; 
                result+=it;
            }
            else if( it == ')'){
                if( count>=1 ){
                    result+=it;
                }
                count--;
            }
            else {
                result+=it;
            }

            if( count <0 ) count =0;
        }
        string temp = ""; 
        count = 0 ; 
        for(int i  = result.size() -1 ; i>= 0 ;i-- ){
            char it = result[i]; 

            if( it == ')'){
                count++; 
                temp+=it;
            }
            else if(it == '('){
                if( count >=1 ){
                    temp+=it; 
                }
                count--; 
            }
            else{
                temp+=it; 
            }
            if( count < 0 ) count =0 ; 
        }
        reverse( temp.begin() , temp.end()); 
        return temp ; 
    }
};