class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        sort(words.begin() , words.end()) ;
        unordered_set<string> st;  
        int n = words.size() ; 
        for( int i = 0 ; i< n-1 ;i++ ){
            if( words[i].size()< k or words[i+1].size() < k ) continue;

            string s1 = words[i].substr(0, k ); 
            if(st.count(s1)) continue ; 
            string s2 = words[i+1].substr(0,k ); 

            if( s1 == s2 ) st.insert( s1 ); 
        }
        return st.size();
    }
};