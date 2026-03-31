class Solution {
public:
    int minimumMoves(string s) {
        int count = 0; 
       
        int n = s.size();
        int i   =0; 
        while(i< n){
            if(s[i] == 'X'){
                count++;
                i+=2;
                // continue;
            }
            i++;
            
        }
        return count;
    }
};