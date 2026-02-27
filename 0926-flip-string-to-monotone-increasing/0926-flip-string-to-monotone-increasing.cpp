class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count1 = 0  , count0 = 0 ; 
        for(auto& it : s ){
            if(it == '0')count0++;
        }
        int ans = count0  ;


        for( auto& it : s ){
            if( it == '1') count1++; 
            else count0--; 
            ans = min( ans , count1+count0);
        }

        return ans ; 

    }
};