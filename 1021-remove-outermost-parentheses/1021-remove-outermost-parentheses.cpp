class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0 ; 
        int right = 0 ; 
        string result = "";
        while( right<s.size()){

            if(s[right] =='('){
                if( count!= 0){
                    result+=s[right];
                }
                
                count++; 
            }
            else{
                count--; 
                if( count!=0){
                    result+=s[right];
                }
            }




            right++;
        }
        return result; 
    }
};