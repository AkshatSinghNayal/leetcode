class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int i = 0;
         int power = 0;
        while(i<s.size()){
            int po = 0;
            char ch = s[i]; 
            if( ch == '('){
                st.push(ch);
                i++; continue;
            }
            while( !st.empty() and s[i] ==')' and i < s.size()){
                po=  ( po < st.size()-1 ) ? st.size()-1 : po;
                st.pop();
                i++;
            }
            power+=(int)pow(2,po);
        }
        return power;
    }
};