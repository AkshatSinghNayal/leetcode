class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int count =0; 
        if( k == 1 ) return r-l+1;
        for(int i =0 ; i<=r ; i++ ){
            int po = (int)pow(i,k); 
            // cout << po << " ";  
            if(po >=l and po<= r ) count++; 
            else{
                if(po > r ) break;
            }
        }
        return count; 
    }
};