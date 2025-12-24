class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort( capacity.rbegin(),capacity.rend()) ; 
        int i  = 0  ; 
        int n  = apple.size() ; 
            long long total = 0 ; 
            long long canHold = capacity[0]; int canHoldIdx =1 ; 
            int count = 1; 
        while( i < n ){
            if( total+apple[i] <= canHold ){
                total+=apple[i];
                i++; 
            }
            else{
               count++; 
               canHold+=capacity[canHoldIdx++];
            }
        }
        return count ; 
    }
};