class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> mp(26); 

        for( auto& it : s ){
            mp[it]++; 
            if( mp[it] == 2 ) return it; 
        }
        return 'a' ; 
    }
};