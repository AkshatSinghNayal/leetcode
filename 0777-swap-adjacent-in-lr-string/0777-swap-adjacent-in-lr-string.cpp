class Solution {
public:
    bool canTransform(string start, string result) {
        int i = 0, j =0 , n  = start.size(); 
        while( i< n and j < n ){
            

            while(i < n and start[i] ==  'X') i++; 
            while( j< n and result[j] ==  'X')j++; 
            if(i >= n || j >= n) break;
            if( start[i]!= result[j]) return false;

            if( start[i] == 'R' and j<i ) return false;
            if( start[i] == 'L' and i<j )  return false;

            i++ ; j++ ; 
        }
        

        while(i < n) {
            if(start[i] != 'X') return false;
            i++;
        }
        while(j < n) {
            if(result[j] != 'X') return false;
            j++;
        }
        
        return true; 
    }
};