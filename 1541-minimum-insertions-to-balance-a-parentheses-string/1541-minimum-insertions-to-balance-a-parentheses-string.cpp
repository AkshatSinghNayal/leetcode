class Solution {
public:
    int minInsertions(string s) {
        stack<char>st; int count = 0 ;
        int n = s.size(); 

        for(int i  = 0; i<n ;i++ ){
            char ch = s[i]; 
            if(ch == '('){
                st.push('('); 
            }
            else{
                int add = (i+1 < n and s[i+1] == ')') ? 1 : 2;
                if( st.empty()){
                    count+=add;
                    if( add == 1 ) i++; 
                }
                else if( i+1 < n and s[i+1] == ')') {
                    st.pop();
                    i++;
                }
                else{
                    count+=1;
                    st.pop();
                }
            }
        }
        return (int)st.size()*2+count;
    }
};