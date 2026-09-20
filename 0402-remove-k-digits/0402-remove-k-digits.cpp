class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";
        if( num.size() == k ) return "0";
        for(auto& it : num){
            while(st.size()>0  and st.back() > it  and k>0 ){
                k--;
                st.pop_back();
            }
            st.push_back(it);
           
        }   
        int i  = 0; 
        while(k-->0 and st.size() >0) st.pop_back();
        while(i<st.size() and st[i] == '0') i++;
        string ans = st.substr(i); 
        return ( ans.size() == 0 ) ? "0" : ans;
    }
};