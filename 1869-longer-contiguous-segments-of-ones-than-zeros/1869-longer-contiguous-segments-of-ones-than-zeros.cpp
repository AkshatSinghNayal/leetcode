class Solution {
public:
    bool checkZeroOnes(string  nums ) {
        int maxi1  = 0 , maxi = 0 ; 
        int count = 0 ; 
        int count0 = 0  ; 
        for(auto& it : nums){
            if( it ==  '1' ) count++ ; 
            else{
                maxi = max( maxi , count ); 
                count = 0 ; 
            }

            if( it == '0' ) count0++; 
            else{
                maxi1 = max(maxi1 , count0); 
                count0 = 0 ;
            }
        }
        maxi = max( maxi , count ); 
        maxi1 = max(maxi1 , count0); 
        return maxi > maxi1  ; 
    
    }
};