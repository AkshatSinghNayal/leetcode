class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long  count =0 , temp = 0 ; 
        for(auto& it : s ){
            if( it == c ) {
                temp++; 
                count+=temp; 
            }
        }
        return count;  
    }
};