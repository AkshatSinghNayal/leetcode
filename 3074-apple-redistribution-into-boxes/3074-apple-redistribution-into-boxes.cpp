class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        long long total = accumulate( apple.begin(),apple.end() , 0 ); 
        sort( capacity.rbegin(), capacity.rend()); 
        int canHold  = 0  , count = 0  ; 
        for( int i = 0  ; i<capacity.size() ; i++){
            canHold +=capacity[i]; 
            count++; 
            if( canHold>= total) break; 
        }
        return count ; 
    }
};