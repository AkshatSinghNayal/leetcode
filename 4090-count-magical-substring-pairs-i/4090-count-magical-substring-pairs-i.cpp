class Solution {
public:
    int countMagicalPairs(string s) {
        int count = 0; 
        int n =s.size(); 
        for(int j = 1; j<=n-1 ; j++ ){
            unordered_map<int,int>hash1; 
            unordered_map<int,int>hash2;
            unordered_set<int>st;

            for(int i=j-1; i>=0 ; i-- ){
                st.insert(s[i]); 
                hash1[st.size()]++; 
            }
            st.clear(); 
            for(int k = j ; k<n; k++ ){
                st.insert(s[k]); 
                hash2[st.size()]++; 
            }

            for(int ch = 1 ; ch<=26 ; ch++ ){
                count = count+ ( hash1[ch]*hash2[ch]); 
            }
        }
        return count;
    }
};