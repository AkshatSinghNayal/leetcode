class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int count = 0; 
        for(int i  = 0 ;i<s.size() ; i++){
            char ch = s[i];

            if( ch == '[') st.push(ch); 
            else{
                if(!st.empty()) st.pop();
            }
        }
        return ( st.size() <=1 ) ? st.size() : ceil(st.size() / 2.0); 
    }
};