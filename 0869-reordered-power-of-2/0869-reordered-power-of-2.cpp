class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string( n ); 
        sort( s.begin(),s.end()); 
            int tempo = stoi(s); 
        if( s[0] != '0' and (tempo&(tempo-1)) == 0 ) return true; 

        while( next_permutation(s.begin(),s.end())){
            int temp = stoi( s) ; 
            if( s[0] != '0' and (temp&(temp-1))== 0) return true ; 

            }
        return false ;
        }
    
};