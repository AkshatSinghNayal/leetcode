class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int count = 0; 

        for(int i  = 0 ;i<s.size(); i++ ){
            char ch = s[i]; 
            if( ch == '(') st.push(1); 
            else{
                if( st.empty() ) count++; 
                else st.pop();
            }
        }
        return st.size()+count;
    }
};