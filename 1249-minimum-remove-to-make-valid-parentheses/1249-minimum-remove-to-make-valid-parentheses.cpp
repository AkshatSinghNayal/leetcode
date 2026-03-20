class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char>st;
        int n = s.size(); 
        string result ="";
        for(int i  = 0  ;i< n ;i++ ){
            char ch = s[i]; 

            if( ch !='(' and ch!=')'){
                result+=ch;
            }
            else if( ch == '('){
                st.push(ch);
                result+=ch;
            }
            else{
                if(!st.empty()){
                    result+=ch;
                    st.pop();
                }
            }
        }
        n = result.size();
        string temp ="" ;
        st = stack<char>(); 
        for( int i = n-1 ; i>= 0  ;i-- ){
            char ch = result[i]; 

            if( ch != '(' and ch!=')'){
                temp+=ch;
            }
            else if( ch == ')' ){
                st.push(ch);
                temp+=ch;
            }
            else{
                if(!st.empty()){
                    temp+=ch; 
                    st.pop(); 
                }
            }

        }

        reverse(temp.begin() , temp.end());
        return temp ; 
    }
};