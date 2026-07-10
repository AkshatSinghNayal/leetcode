class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n  = s.size(); 
        int cheat = 0 , notCheat = 0 ; 
        for(auto& it : t ){

            if( s[cheat] ==  it ) cheat++; 
            else cheat = max(cheat , notCheat+1 ); 

            if( s[notCheat] == it ){
                notCheat++; 
            }

            if( cheat >= n or notCheat >= n ) return true;

        }
        cout<< cheat << " " << notCheat; 
        return false;
    }
};