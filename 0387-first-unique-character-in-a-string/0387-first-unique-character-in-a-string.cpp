class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp ; 
        char temp ;
        for( int i = 0 ; i<s.size() ; i++){
            mp[s[i]]++; 
        }

         for( int i  = 0 ; i<s.size() ; i++){
            char c = s[i]; 
            if( mp[c] == 1 ){
                temp = c; 
                break;
            }
         }
        int a = s.find(temp); 
        return a ; 
    }
};