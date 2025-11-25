class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if( k  == 1 ) return 1; 
        if( k% 2 == 0 || k%5 == 0  ) return -1 ; 

        long long ans  = 0  ; 
        int count =  1; 
        bool flag =  false; 
         for( int i = 0  ; i<=k ; i++){
            ans =  (ans%k*10+1)%k; 
            if( ans ==  0  ){
                flag = true; 
                break; 
            }
            count++; 
         }

        return (flag ) ? count : -1;
    }
};