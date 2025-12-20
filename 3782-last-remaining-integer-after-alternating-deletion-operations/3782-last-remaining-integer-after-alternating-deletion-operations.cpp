class Solution {
public:
    long long lastInteger(long long n) {
        long long rem = n ; 
        long long gap = 1; 
        long long last =1 ; 
        bool left = true; 
        while( rem > 1){
            if( left == false and  (rem%2 == 0) ){
                last = last+gap ; 
            }
            rem =( rem+1)/2 ; 
            gap*=2 ; 
            left=!left ; 
            

        }  
        return last ; 
    }
};