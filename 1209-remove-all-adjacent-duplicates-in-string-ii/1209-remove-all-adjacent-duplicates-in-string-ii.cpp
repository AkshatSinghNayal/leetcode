class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(auto& it : s ){
            if(!st.empty() and st.top().first == it ){
                st.top().second++;

                if( st.top().second == k ) st.pop();
            }
            else{
                st.push({it,1});
            }
        }
        string ans ="";
        while(!st.empty()){
            ans = string( st.top().second , st.top().first ) + ans; 
            st.pop();
        }
        return ans;
    }
};