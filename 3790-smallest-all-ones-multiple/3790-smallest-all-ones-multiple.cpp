class Solution {
public:
    int minAllOneMultiple(int k) {
        if( k%2 == 0 or k%5 == 0 ) return -1 ; 
        int i  = 0; 
        int total = 0 ; int count = 0 ; 
        while(i<=k){
            count++; i++; 
            total = (total*10+1)%k; 
            if( total == 0 ) break;
            
        }
        return count; 
    }
};