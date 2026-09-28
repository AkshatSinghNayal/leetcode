class Solution {
public:
    int maxDepth(string s) {
        int count = 0  , maxi = 0 ; 
        for(auto& it : s ){
            if( it == '(') count++; 
            else if( it == ')') count--; 
            maxi = max(maxi , count);
        }
        return maxi;
    }
};