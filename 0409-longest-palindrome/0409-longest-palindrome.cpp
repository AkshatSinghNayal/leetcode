class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp ; 
        for( auto& it : s ){
            mp[it]++;
        }

        int count = 0 ; 
        bool odd =  false ; 
        for( auto& it : mp ){
            if( it.second % 2 == 0 ) count+=it.second ; 
            else{
                count+= it.second-1 ; 
                odd = true;  
            }
        }
        return ( odd ==  true) ? count+1 : count ; 
    }
};