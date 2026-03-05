class Solution {
public:
    int minimizedStringLength(string s) {
        set<char>st;
        for(auto&it : s ){
            st.insert({it});
        }
        return st.size();
    }
};