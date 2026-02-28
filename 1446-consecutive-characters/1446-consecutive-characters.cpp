class Solution {
public:
    int maxPower(string s) {
        char ch = ' '; 
        int count = 0 ; 
        int maxi = 0 ; 
        for(auto& it : s ){
            if( it != ch ){
                maxi = max(maxi ,count ); 
                ch = it ; 
                count=1  ; 
            }
            else{
                count++; 
            }
        }
        maxi = max( maxi , count ); 
        return maxi ; 
    }
};